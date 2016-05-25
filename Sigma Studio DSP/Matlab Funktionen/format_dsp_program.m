string = fileread ('/home/andreas/Desktop/Program.dat');

i=1;
hexcode = [];
while i<length(string)
    hexcode = sprintf('%s0x%s, ',hexcode,string(i:i+1));
    i=i+2;
    hexcode = sprintf('%s0x%s, ',hexcode,string(i:i+1));
    i=i+2;
    hexcode = sprintf('%s0x%s, ',hexcode,string(i:i+1));
    i=i+2;
    hexcode = sprintf('%s0x%s, ',hexcode,string(i:i+1));
    i=i+4;
end
    
hexcode = hexcode(1:(length(hexcode)-2));