#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

rm -rf outfile
echo -e "${RED}******************************************************"
echo     "     < infile grep -u a | wc -l > outfile           **"
echo -e "******************************************************${NC}"
< infile grep -u a | wc -l > outfile
echo cat outfile
cat outfile

rm -rf outfile
echo -e "${GREEN}******************************************************"
echo "**    ./pipex infile grep -u a wc -l outfile        **"
echo -e "******************************************************${NC}"
./pipex infile "grep -u a" "wc -l" outfile
echo cat outfile
cat outfile

rm -rf outfile
echo -e "${RED}******************************************************"
echo "**     < infile grepp -u a | wc -l > outfile        **"
echo -e "******************************************************${NC}"
< infile grepp -u a | wc -l > outfile
echo cat outfile
cat outfile

rm -rf outfile
echo -e "${GREEN}******************************************************"
echo "**    ./pipex infile grepp -u a wc -l outfile       **"
echo -e "******************************************************${NC}"
./pipex infile "grepp -u a" "wc -l" outfile
echo cat outfile
cat outfile

rm -rf outfile
echo -e "${RED}******************************************************"
echo "**     < infile grep -u a | wcc -l > outfile        **"
echo -e "******************************************************${NC}"
< infile grep -u a | wcc -l > outfile
echo cat outfile
cat outfile

rm -rf outfile
echo -e "${GREEN}******************************************************"
echo "**    ./pipex infile grep -u a wcc -l outfile       **"
echo -e "******************************************************${NC}"
/pipex infile "grep -u a" "wcc -l" outfile
echo cat outfile
cat outfile
echo -e "${GREEN}******************************************************"
echo "**    **************   TESTER        *****************"
echo -e "******************************************************${NC}"
./test/run.sh
