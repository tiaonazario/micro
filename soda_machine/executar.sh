set -e

ghdl -a sodamachine.vhd
ghdl -a partedecontrole.vhd
ghdl -a parteoperativa.vhd
ghdl -a registrador.vhd
ghdl -a sodamachine_tb.vhd

ghdl -e sodamachine_tb
ghdl -r sodamachine_tb --wave=./waves/sodamachine_tb.ghw

gtkwave ./waves/sodamachine_tb.ghw

