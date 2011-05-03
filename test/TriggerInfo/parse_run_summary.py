#!/usr/bin/python

file = open ("RunSummary_160329_163876.txt")

trigger_keys = []
key_subversion_dict = {}


for line in file : 
    split_line = line.split()
    for entry in split_line:
        if "/HLT/"     not in entry: continue
        if "/cdaq/"    not in entry: continue

        if "Interfill" in entry: continue
        if "2760"      in entry: continue
        if "special"   in entry: continue
        if "cosmic"    in entry: continue
        
        if entry not in trigger_keys :
            trigger_keys.append ( entry ) 

for key in trigger_keys:
    fields = key.split("/") 
    version     = fields[5 ][1:]
    sub_version = fields[-1][1:]

    print key

    if version in key_subversion_dict.keys(): 
        if sub_version not in key_subversion_dict[version]:
            key_subversion_dict[version].append ( sub_version ) 
    else : 
        key_subversion_dict[version] = [ sub_version ]

    
for version in key_subversion_dict:
    subversion_list_string = ""
    for subversion in key_subversion_dict[version]:
        subversion_list_string = subversion_list_string + "V"+subversion+", "
    subversion_list_string = subversion_list_string[:-2]

    print "     Key version: "+version+" had subversions: "+subversion_list_string
    
