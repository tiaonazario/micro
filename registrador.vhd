library ieee;
use ieee.std_logic_1164.all; 

entity registrador is  
  port (tot_ld, tot_clr, clk, rst: in std_logic;
			soma: in std_logic_vector (7 downto 0);
         tot: out std_logic_vector (7 downto 0)
		 );
	end registrador;

architecture estrutura_registrador of registrador is

begin 
    process (clk, rst)
	 begin 
	     if rst = '1' then
				tot <= b"00000000";
		  elsif rising_edge(clk) then
				if tot_clr = '1' then tot <= b"00000000";
				elsif tot_ld = '1' then tot <= soma;
				end if;
		  end if;
		  
	end process;
	
end estrutura_registrador;
