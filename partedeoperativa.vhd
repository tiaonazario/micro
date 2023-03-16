library ieee;
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity parteoperativa is  
  port (tot_ld, tot_clr, clock, reset: in std_logic;
			moeda, produto: in std_logic_vector (1 downto 0);
         tot_lt: out std_logic;
			troco: out std_logic_vector (7 downto 0)
		 );
end parteoperativa;

architecture estrutura_parteoperativa of parteoperativa is
	component registrador is  
		port (
			tot_ld, tot_clr, clk, rst: in std_logic;
			soma: in std_logic_vector (7 downto 0); 
			tot: out std_logic_vector (7 downto 0)
		);
	end component;
	
	signal soma, tot, a, s: std_logic_vector(7 downto 0);
	signal tot_lt_s: std_logic:='0';

begin

	reg: registrador port map(
		tot_ld => tot_ld,
		tot_clr => tot_clr,
		clk => clock,
		rst => reset,
		soma => soma,
		tot => tot
	);
	
	a <= b"00000001" when moeda="01" else
	b"00000010" when moeda="11" else b"00000000";
	
	s <= b"00000001" when produto="01" else
	b"00000110" when produto="11" else b"00000000";
	
	
	tot_lt_s <= '1' when tot < s else '0';
	tot_lt <= tot_lt_s;
	soma <= std_logic_vector(unsigned(tot) + unsigned(a));
	troco <= std_logic_vector(unsigned(tot) - unsigned (s)) when tot_lt_s = '0' else b"00000000";
	
	

end estrutura_parteoperativa;
