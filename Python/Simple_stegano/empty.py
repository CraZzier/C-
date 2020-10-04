from PIL import Image
import binascii
im = Image.open('ok.png')
pixels = im.load()
for i in range(im.size[0]):    # for every col:
    for j in range(im.size[1]):
    	if pixels[i,j][0]&1:
    		pixels[i,j] = (pixels[i,j][0]-1,pixels[i,j][1],pixels[i,j][2])
    	if pixels[i,j][1]&1:
    		pixels[i,j] = (pixels[i,j][0],pixels[i,j][1]-1,pixels[i,j][2])
    	if pixels[i,j][2]&1:
    		pixels[i,j] = (pixels[i,j][0],pixels[i,j][1],pixels[i,j][2]-1)

im.show()
im.save("czyste.png")
