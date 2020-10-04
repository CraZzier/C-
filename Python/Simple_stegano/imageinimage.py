from PIL import Image
import binascii
def inttobinstr(liczba):
	tekst=""
	op=0
	while op<8:
		num=int(128 * (1/pow(2,op)))
		if liczba & num:
			tekst+='1'
		else:
			tekst+='0'
		op+=1
	return tekst

im = Image.open('czyste.png')
im1 = Image.open('kod.png')
pixels = im.load()
pixels1 = im1.load()
kodflagi=""
for j in range(im1.size[1]):
	for i in range(im1.size[0]):
		kodflagi+=inttobinstr(pixels1[i,j][0])
		kodflagi+=inttobinstr(pixels1[i,j][1])
		kodflagi+=inttobinstr(pixels1[i,j][2])
x=0
y=0
i=0
licznik=0
while i < (len(kodflagi)):
	if i%3==0:
		if kodflagi[i]=='1':
			pixels[x,y]=(pixels[x,y][0]+1,pixels[x,y][1],pixels[x,y][2])
		elif kodflagi[i]=='0':
			pixels[x,y]=(pixels[x,y][0],pixels[x,y][1],pixels[x,y][2])
		i+=1
			
	if i%3==1:
		if kodflagi[i]=='1':
			pixels[x,y]=(pixels[x,y][0],pixels[x,y][1]+1,pixels[x,y][2])
		elif kodflagi[i]=='0':
			pixels[x,y]=(pixels[x,y][0],pixels[x,y][1],pixels[x,y][2])
		i+=1

	if i%3==2:
		if kodflagi[i]=='1':
			pixels[x,y]=(pixels[x,y][0],pixels[x,y][1],pixels[x,y][2]+1)
		elif kodflagi[i]=='0':
			pixels[x,y]=(pixels[x,y][0],pixels[x,y][1],pixels[x,y][2])
		i+=1	

	if x>=(im.size[0]-1):
		y+=1
		x=0
	else:
		x+=1
print (kodflagi)
#im.show()
im.save("zakodowane.png")