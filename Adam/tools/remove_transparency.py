import PIL
import os
from os import listdir
from os.path import isfile, join

from PIL import Image
from pip._vendor.msgpack.fallback import xrange


def get_wd():
    wd = input("Enter a path to the directory to scan:")
    if os.path.isdir(wd):
        return wd
    return None


def resize_images(dir):
    for path, folders, files in os.walk(dir):
        for f in files:
            if f != 'animations.txt':
                img = Image.open(os.path.join(path, f))
                img = img.convert('RGBA')
                pixdata = img.getdata()
                new_data = []
                for item in pixdata:
                    if item[3] == 0:
                        tmp = list(item)
                        tmp[3] = 1
                        new_data.append(tuple(tmp))
                    else:
                        new_data.append(item)
                img = Image.new(img.mode, img.size)
                print(pixdata)
                img.putdata(new_data)

                img.save(os.path.join(path, f))


if __name__ == '__main__':
    wd = get_wd()
    while wd is None:
        wd = get_wd()
    resize_images(wd)
