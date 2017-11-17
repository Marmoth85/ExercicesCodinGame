import sys
import math

n = int(input())  # Number of elements which make up the association table.
q = int(input())  # Number Q of file names to be analyzed.

extensions = {} 
for i in range(n):
    ext, mt = input().split() # ext : file extension, mt: MIME type
    extensions[ext.lower()] = mt
    
for i in range(q):
    mime_type = "UNKNOWN"
    fname = input()  # One file name per line.
    extension = fname.split(".")
    if len(extension) >= 2:
        extension_file = extension[-1]
        if len(extension_file) > 0:
            mime_type = extensions.get(extension_file.lower(), "UNKNOWN")
    print(mime_type)