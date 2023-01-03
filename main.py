import cv2

img = cv2.imread("/Users/letri/Downloads/pixil-frame-0 (1).png")
fo = open('file.out', 'w')
x, y, dim = img.shape[0], img.shape[1], img.shape[2]

fo.write("short picture[ROW][COL][3] = {\n")

for row in range(x):
    fo.write("  {")
    for col in range(y):
        string_out = "{"
        string_out += f'{img[row][col][2]}, {img[row][col][1]}, {img[row][col][0]}'
        if col == y - 1:
            string_out += "}"
        else:
            string_out += "}, "
        fo.write(string_out)
    if row == x - 1:
        fo.write("}")
    else:
        fo.write("},")
    fo.write("\n")
fo.write("};")