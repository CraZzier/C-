from PIL import Image
im = Image.open("ok.png")
pixele = im.load()
nowy = Image.new('RGB', (1600,800), (255,255,255))
pix = nowy.load()
a=0
b=0
x=0
y=0
p=0
q=0
r=0
jj=0
for j in range(im.size[1]):
	for i in range((im.size[0])*3):
		if pixele[i/3,j][i%3]&1:
			a=(a<<1)+1

		else:
			a=(a<<1)

		b=b+1
		if (b==8) or (b==16) or (b==24):
			if b==8:
				p=a

			if b==16:
				q=a

			if b==24:
				r=a

			pix[x,y]=(p,q,r)
			a=0

		if b==24:
			b=0
			x=x+1

		if x==1600:
			x=0
			y=y+1


nowy.show()
nowy.save("lamus.jpg")