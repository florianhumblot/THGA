import os
from os import listdir
from os.path import isfile, join


def get_wd():
    wd = input("Enter a path to the directory to scan:")
    if os.path.isdir(wd):
        return wd
    return None


def remove_whitespace_from_name(dir):
    for path, folders, files in os.walk(dir):
        for f in files:
            os.rename(os.path.join(path, f), os.path.join(path, f.replace(' ', '')))
        for i in range(len(folders)):
            new_name = folders[i].replace(' ', '')
            os.rename(os.path.join(path, folders[i]), os.path.join(path, new_name))
            folders[i] = new_name


if __name__ == '__main__':
    wd = get_wd()
    while wd is None:
        wd = get_wd()
    remove_whitespace_from_name(wd)

