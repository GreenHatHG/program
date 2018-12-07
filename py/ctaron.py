#!/usr/bin/env python
from cyaron import *
import string

letters = string.ascii_letters 
for i in range(1, 30):
    str = String.random((1, 30), charset=letters)
    io = IO(file_prefix = "test", data_id = i, disable_output=True)
    io.input_write(str)
