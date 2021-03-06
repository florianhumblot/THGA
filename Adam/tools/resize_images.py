import PIL
import os
from os import listdir
from os.path import isfile, join

from PIL import Image


def get_wd():
    wd = input("Enter a path to the directory to scan:")
    if os.path.isdir(wd):
        return wd
    return None


def resize_images(dir):
    for path, folders, files in os.walk(dir):
        for f in files:
            if f != 'animations.txt':
                basewidth = 192
                img = Image.open(os.path.join(path, f))
                wpercent = (basewidth / float(img.size[0]))
                hsize = 192
                img = img.resize((basewidth, hsize), PIL.Image.ANTIALIAS)
                img.save(os.path.join(path, f))



#if __name__ == '__main__':
wd = get_wd()
while wd is None:
    wd = get_wd()
resize_images(wd)

