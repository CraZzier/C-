from PIL import Image
import binascii

def strtoint(wyraz):
	dl=len(wyraz)
	i=0
	suma=0
	while (i<dl):
		if (wyraz[i]=="1"):
			suma+=(pow(2,(dl-i-1)))
		i+=1
	return suma

im = Image.open('zakodowane.png')
pixels = im.load()
str=""
for j in range(im.size[1]):    # for every col:
    for i in range(im.size[0]):
    	if pixels[i,j][0]&1:
    		str+="1"
    	else:
    		str+="0"
    	if pixels[i,j][1]&1:
    		str+="1"
    	else:
    		str+="0"
    	if pixels[i,j][2]&1:
    		str+="1"
    	else:
    		str+="0"
print (str)
im1 = Image.new("RGB",(800,400),0)
pixels1 = im1.load()
i=0
tmp=""
a=0
b=0
c=0
szer=0
wys=0
while i<len(str):
	for x in range(8):
		tmp+=str[i]
		i+=1
	a=strtoint(tmp)
	tmp=""
	for x in range(8):
		tmp+=str[i]
		i+=1
	b=strtoint(tmp)
	tmp=""
	for x in range(8):
		tmp+=str[i]
		i+=1
	c=strtoint(tmp)
	tmp=""
	pixels1[szer,wys]=(a,b,c)
	if szer>=(im1.size[0]-1):
		wys+=1
		szer=0
	else:
		szer+=1
im1.show()
im1.save("lamus.png")
