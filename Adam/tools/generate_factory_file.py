import os
import re
def get_wd():
    wd = input("Enter a path to the directory to scan:")
    if os.path.isdir(wd):
        return wd
    return None


def getListOfFiles(dirName):
    # create a list of file and sub directories
    # names in the given directory
    listOfFile = os.listdir(dirName)
    allFiles = list()
    # Iterate over all the entries
    for entry in listOfFile:
        # Create full path
        fullPath = os.path.join(dirName, entry)
        # If entry is a directory then get the list of files in this directory
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            allFiles.append(dirName+entry)

    return allFiles


def split_uppercase(str):
    x = ''
    i = 0
    for c in str:
        # print(c, str[i-1])
        if i == 0:
            x += c
        elif c.isupper() and not str[i-1].isupper():
            x += ' %s' % c
        else:
            x += c
        i += 1
    return x.strip()



def atoi(text):
    return int(text) if text.isdigit() else text

def natural_keys(text):
    '''
    alist.sort(key=natural_keys) sorts in human order
    http://nedbatchelder.com/blog/200712/human_sorting.html
    (See Toothy's implementation in the comments)
    '''
    return [ atoi(c) for c in re.split('(\d+)', text) ]

alist=[
    "something1",
    "something12",
    "something17",
    "something2",
    "something25",
    "something29"]



if __name__ == '__main__':
    wd = get_wd()
    while wd is None:
        wd = get_wd()
    files = getListOfFiles(wd)[1:]
    files.sort(key=natural_keys)
    print(files)
    target_file = 'C:/ti-software/Adam/Adam/assets/animations/animations.txt'
    base_path = 'animations/'
    with open(target_file, 'w+') as f:
        for file in files:
            split_name = split_uppercase(file).split('\\')
            # split_name.append(split_name[1].split('(')[0])
            split_name = split_name[6].split(' ')
            print(split_name)
            line = ''
            line += split_name[0] + ' ' + split_name[1] + ' '
            line += base_path + split_name[0] + split_name[1] + '/' + split_name[2]
            line += "\n"
            f.write(line)