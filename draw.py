import Image

n = int(input())

grid = [[0 for x in range(2 * n)] for y in range(2 * n)]

for i in range(0, 2 * n):
	s = raw_input()
	s = s.split()
	for j in range(0, 2 * n):
		grid[i][j] = s[j]
	

img = Image.new( 'RGB', (2 * n, 2 * n), "white") # create a new black image
pixels = img.load()

for i in range(img.size[0]):
	for j in range(img.size[1]):
		if(grid[j][i] == '0'):
			pixels[i, j] = (255, 255, 255) 
		else:
			pixels[i, j] = (0, 0, 0)

img.save("tmp.jpg")
