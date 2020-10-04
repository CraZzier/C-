package main

import (
	"encoding/csv"
	"fmt"
	"math"
	"math/rand"
	"os"
	"strconv"
	"time"

	"github.com/go-echarts/go-echarts/charts"
)

type MLP struct {
	teachrate          float64
	hiddenlayernumber  int
	hiddenneuronnumber int
	repeatnumber       int
	startovernumber    int
	acceptance         int
	activatefunction   string
}

func (mlp *MLP) init(tr float64, hln int, hnn int, rn int, son int, a int, af string) bool {
	mlp.teachrate = tr
	mlp.hiddenlayernumber = hln
	mlp.hiddenneuronnumber = hnn
	mlp.repeatnumber = rn
	mlp.startovernumber = son
	mlp.acceptance = a
	mlp.activatefunction = af
	return true
}
func (mlp MLP) printfeat() {
	fmt.Print(mlp.teachrate)
	fmt.Print(mlp.hiddenlayernumber)
	fmt.Print(mlp.hiddenneuronnumber)
	fmt.Print(mlp.repeatnumber)
	fmt.Print(mlp.startovernumber)
	fmt.Print(mlp.acceptance)
	fmt.Print(mlp.activatefunction)
}
func (mlp MLP) getRandom(min float64, max float64) float64 {
	x := (rand.Float64())*(max-min) + min
	return x
}

func usigmoid(x float64) float64 {
	return 1 / (1 + math.Exp(-x))
}
func ubisigmoid(x float64) float64 {
	return 2/(1+math.Exp(-x)) - 1
}
func sgn(x float64) float64 {
	if x > 0 {
		return 1
	} else {
		return -1
	}
}
func tanhder(x float64) float64 {
	return (1 - math.Pow(math.Tanh(x), 2))
}
func usigmoidder(x float64) float64 {
	return (1 / (1 + math.Exp(-x))) * (1 - (1 / (1 + math.Exp(-x))))
}
func ubisigmoidder(x float64) float64 {
	return 2 * ((1 / (1 + math.Exp(-x))) * (1 - (1 / (1 + math.Exp(-x)))))
}
func activateFunc(nameFunc string, x float64) float64 {
	if nameFunc == "sgn" {
		return sgn(x)
	}
	if nameFunc == "tanh" {
		return math.Tanh(x)
	}
	if nameFunc == "usigmoid" {
		return usigmoid(x)
	}
	if nameFunc == "ubisigmoid" {
		return ubisigmoid(x)
	}
	return sgn(x)
}
func activateFuncDer(nameFunc string, x float64) float64 {
	if nameFunc == "sgn" {
		return ubisigmoidder(x)
	}
	if nameFunc == "tanh" {
		return tanhder(x)
	}
	if nameFunc == "usigmoid" {
		return usigmoidder(x)
	}
	if nameFunc == "ubisigmoid" {
		return ubisigmoidder(x)
	}
	return sgn(x)
}
func (mlp *MLP) initWeight(min float64, max float64, inputneurons int, outputneurons int) [][][]float64 {
	weights := make([][][]float64, mlp.hiddenlayernumber+1)
	weights[0] = make([][]float64, inputneurons)
	for i := 0; i < inputneurons; i++ {
		weights[0][i] = make([]float64, mlp.hiddenneuronnumber)
	}

	for t := 1; t < mlp.hiddenlayernumber; t++ {
		weights[t] = make([][]float64, mlp.hiddenneuronnumber)
		for i := 0; i < mlp.hiddenneuronnumber; i++ {
			weights[t][i] = make([]float64, mlp.hiddenneuronnumber)
		}

	}
	weights[mlp.hiddenlayernumber] = make([][]float64, mlp.hiddenneuronnumber)
	for i := 0; i < mlp.hiddenneuronnumber; i++ {
		weights[mlp.hiddenlayernumber][i] = make([]float64, outputneurons)
	}
	for i := 0; i < len(weights); i++ {
		for o := 0; o < len(weights[i]); o++ {
			for p := 0; p < len(weights[i][o]); p++ {
				weights[i][o][p] = mlp.getRandom(min, max)
			}
		}
	}
	return weights
}
func (mlp *MLP) getShuffledArray(recordnumber int) []int {
	order := []int{}
	for i := 0; i < recordnumber; i++ {
		order = append(order, i)
	}
	rand.Seed(time.Now().UnixNano())
	rand.Shuffle(len(order), func(i, j int) { order[i], order[j] = order[j], order[i] })
	return order
}
func (mlp MLP) fulfilRecord(index int, data [][]string, datalength int) []float64 {
	currentrecord := []float64{}
	for p := 0; p < datalength; p++ {
		temp, _ := strconv.ParseFloat(data[index][p], 64)
		currentrecord = append(currentrecord, temp)
	}
	return currentrecord
}
func (mlp *MLP) singleTeach(weights [][][]float64, currentrecord []float64, inputneurons int, outputneurons int) [][][]float64 {
	hneuron := make([][]float64, mlp.hiddenlayernumber)
	hneuronout := make([][]float64, mlp.hiddenlayernumber)
	hneuronerror := make([][]float64, mlp.hiddenlayernumber)
	for i := 0; i < mlp.hiddenlayernumber; i++ {
		hneuron[i] = make([]float64, mlp.hiddenneuronnumber)
		hneuronout[i] = make([]float64, mlp.hiddenneuronnumber)
		hneuronerror[i] = make([]float64, mlp.hiddenneuronnumber)
	}
	lneuron := make([]float64, outputneurons)
	lneuronout := make([]float64, outputneurons)
	lneuronerror := make([]float64, outputneurons)
	for i := 0; i < mlp.hiddenneuronnumber; i++ {
		for o := 0; o < inputneurons; o++ {
			hneuron[0][i] += weights[0][o][i] * currentrecord[o]
		}
		hneuronout[0][i] = activateFunc(mlp.activatefunction, hneuron[0][i])
	}
	for k := 1; k < mlp.hiddenlayernumber; k++ {
		for i := 0; i < mlp.hiddenneuronnumber; i++ {
			for o := 0; o < mlp.hiddenneuronnumber; o++ {
				hneuron[k][i] += weights[k][o][i] * hneuronout[k][o]
			}
			hneuronout[k][i] = activateFunc(mlp.activatefunction, hneuron[0][i])
		}
	}
	for i := 0; i < outputneurons; i++ {
		for o := 0; o < mlp.hiddenneuronnumber; o++ {
			lneuron[i] += weights[mlp.hiddenlayernumber][o][i] * hneuronout[mlp.hiddenlayernumber-1][o]
		}
		lneuronout[i] = activateFunc(mlp.activatefunction, lneuron[i])
	}
	/* Błędy */
	for i := 0; i < outputneurons; i++ {
		lneuronerror[i] = (currentrecord[inputneurons+i] - lneuronout[i]) * activateFuncDer(mlp.activatefunction, lneuron[i])
	}
	for i := 0; i < outputneurons; i++ {
		for o := 0; o < mlp.hiddenneuronnumber; o++ {
			hneuronerror[mlp.hiddenlayernumber-1][o] += weights[mlp.hiddenlayernumber][o][i] * lneuronerror[i] * activateFuncDer(mlp.activatefunction, hneuron[mlp.hiddenlayernumber-1][o])
		}
	}
	for k := 1; k < mlp.hiddenlayernumber; k++ {
		for i := 0; i < mlp.hiddenneuronnumber; i++ {
			for o := 0; o < mlp.hiddenneuronnumber; o++ {
				hneuronerror[mlp.hiddenlayernumber-k-1][i] += weights[mlp.hiddenlayernumber-k][o][i] * hneuronerror[mlp.hiddenlayernumber-k][i] * activateFuncDer(mlp.activatefunction, hneuron[mlp.hiddenlayernumber-k][i])
			}
		}
	}
	/* modyfkiacja wag */
	for i := 0; i < outputneurons; i++ {
		for o := 0; o < mlp.hiddenneuronnumber; o++ {
			weights[mlp.hiddenlayernumber][o][i] = weights[mlp.hiddenlayernumber][o][i] + mlp.teachrate*lneuronerror[i]*hneuronout[mlp.hiddenlayernumber-1][o]
		}
	}
	for k := 1; k < mlp.hiddenlayernumber; k++ {
		for i := 0; i < mlp.hiddenneuronnumber; i++ {
			for o := 0; o < mlp.hiddenneuronnumber; o++ {
				weights[mlp.hiddenlayernumber-k][o][i] = weights[mlp.hiddenlayernumber-k][o][i] + mlp.teachrate*hneuronerror[mlp.hiddenlayernumber-k][i]*hneuronout[mlp.hiddenlayernumber-1-k][o]
			}
		}
	}
	for i := 0; i < mlp.hiddenneuronnumber; i++ {
		for o := 0; o < inputneurons; o++ {
			weights[0][o][i] = weights[0][o][i] + mlp.teachrate*hneuronerror[0][i]*currentrecord[o]
		}
	}
	return weights
}
func (mlp *MLP) teach(datafile string, outputneurons int) [][][]float64 {
	data, err := os.Open(datafile)
	if err != nil {
		fmt.Print("Wystąpił błąd wczytywania pliku")
	}
	defer data.Close()
	datalines, err := csv.NewReader(data).ReadAll()
	if err != nil {
		fmt.Print("Wystąpił błąd czytania pliku")
	}
	datalinesnumber := len(datalines)
	datalinelength := len(datalines[0])
	inputneurons := datalinelength - outputneurons
	weights := mlp.initWeight(-5, 5, inputneurons, outputneurons)
	mse := make([]float64, mlp.repeatnumber)
	correctness := make([]float64, mlp.repeatnumber)
	sensitivity := make([]float64, mlp.repeatnumber)
	specificity := make([]float64, mlp.repeatnumber)
	ox := make([]int, mlp.repeatnumber)

	for i := 0; i < mlp.repeatnumber; i++ {
		o := i % datalinesnumber
		currentrecord := mlp.fulfilRecord(o, datalines, datalinelength)
		weights = mlp.singleTeach(weights, currentrecord, inputneurons, outputneurons)
		correctness[i], mse[i], sensitivity[i], specificity[i] = mlp.test(weights, inputneurons, outputneurons, datafile)
		ox[i] = i + 1
	}
	bar := charts.NewLine()
	bar.SetGlobalOptions(charts.TitleOpts{Title: "Poprawność"})
	bar.AddXAxis(ox).AddYAxis("Correct", correctness)
	f, err := os.Create("bar.html")
	bar.Render(f)
	bar1 := charts.NewLine()
	bar1.SetGlobalOptions(charts.TitleOpts{Title: "Mse"})
	bar1.AddXAxis(ox).AddYAxis("Correct", mse)
	f1, err := os.Create("bar1.html")
	bar1.Render(f1)
	bar2 := charts.NewLine()
	bar2.SetGlobalOptions(charts.TitleOpts{Title: "Czułość"})
	bar2.AddXAxis(ox).AddYAxis("Correct", sensitivity)
	f2, err := os.Create("bar2.html")
	bar2.Render(f2)
	bar3 := charts.NewLine()
	bar3.SetGlobalOptions(charts.TitleOpts{Title: "Specyficzność"})
	bar3.AddXAxis(ox).AddYAxis("Correct", specificity)
	f3, err := os.Create("bar3.html")
	bar3.Render(f3)
	return weights
}
func (mlp *MLP) test(weights [][][]float64, inputneurons int, outputneurons int, filename string) (float64, float64, float64, float64) {
	hneuronout := make([][]float64, mlp.hiddenlayernumber)
	lneuronout := make([]float64, outputneurons)

	data, _ := os.Open(filename)
	defer data.Close()
	datalines, _ := csv.NewReader(data).ReadAll()
	datalinesnumber := len(datalines)
	datalinelength := len(datalines[0])
	var temp float64 = 0
	var t1 float64 = 0
	correctanswer := 0
	diff := 0.00
	tp := 0.00
	tn := 0.00
	fp := 0.00
	fn := 0.00

	for x := 0; x < datalinesnumber; x++ {
		hneuronout[0] = make([]float64, mlp.hiddenneuronnumber)
		for i := 0; i < mlp.hiddenneuronnumber; i++ {
			t1 = 0
			for o := 0; o < inputneurons; o++ {
				temp, _ := strconv.ParseFloat(datalines[x][o], 64)
				t1 += temp * weights[0][o][i]
			}
			hneuronout[0][i] = activateFunc(mlp.activatefunction, t1)
		}
		for k := 1; k < mlp.hiddenlayernumber; k++ {
			hneuronout[k] = make([]float64, mlp.hiddenneuronnumber)
			for i := 0; i < mlp.hiddenneuronnumber; i++ {
				t1 = 0
				for o := 0; o < mlp.hiddenneuronnumber; o++ {
					temp = hneuronout[k-1][o]
					t1 += temp * weights[k][o][i]
				}
				hneuronout[k][i] = activateFunc(mlp.activatefunction, t1)
			}
		}
		for i := 0; i < outputneurons; i++ {
			t1 = 0
			for o := 0; o < mlp.hiddenneuronnumber; o++ {
				temp = float64(hneuronout[mlp.hiddenlayernumber-1][o])
				t1 += temp * weights[mlp.hiddenlayernumber][o][i]
			}
			lneuronout[i] = activateFunc(mlp.activatefunction, t1)
		}
		/* sprawdzenie wyniku */
		rounded := 0.00
		correct := 0
		for i := 0; i < outputneurons; i++ {
			temp, _ := strconv.ParseFloat(datalines[x][datalinelength-outputneurons+i], 64)
			diff += 1.00 / 2.00 * float64(math.Pow(temp-lneuronout[i], 2))
		}
		for i := 0; i < outputneurons; i++ {
			temp, _ := strconv.ParseFloat(datalines[x][datalinelength-outputneurons+i], 64)
			rounded = math.Round(lneuronout[i])
			if rounded == temp {

				if temp == 0 {
					tn++
				} else {
					tp++
				}
				correct++
			} else {
				if temp == 0 {
					fn++
				} else {
					fp++
				}
			}
		}
		if correct == outputneurons {
			correctanswer++
		}
	}

	var correctness float64 = float64(float64(correctanswer) / float64(datalinesnumber) * 100.00)

	var sensitivity float64 = tp / (tp + fn)
	var specificity float64
	if fp+tn == 0 {
		specificity = 0
	} else {
		specificity = tn / (fp + tn)
	}
	if fn+tp == 0 {
		sensitivity = 0
	} else {
		sensitivity = tp / (tp + fn)
	}
	fmt.Println(tp)
	fmt.Println(fn)
	fmt.Println(tn)
	fmt.Println(fp)
	return correctness, diff, sensitivity, specificity

}

func main() {
	teachrate := 0.01
	hiddenlayernumber := 1
	hiddenneuronnumber := 5
	repeatnumber := 8000
	startovernumber := 15
	acceptance := 80
	activatefunction := "ubisigmoid"
	network := new(MLP)
	network.init(teachrate, hiddenlayernumber, hiddenneuronnumber, repeatnumber, startovernumber, acceptance, activatefunction)
	weights := network.teach("Immunotherapy_learn.csv", 1)
	network.test(weights, 7, 1, "Immunotherapy_check.csv")

}
