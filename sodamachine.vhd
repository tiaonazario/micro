library ieee;
use ieee.std_logic_1164.all; 
use ieee.numeric_std.all;

entity sodamachine is  
  port ( moeda, produto: in std_logic_vector (1 downto 0); 
         velocidade: in std_logic_vector (7 downto 0);
			c, clock, reset: in std_logic;
			d: out std_logic;
			troco: out std_logic_vector (7 downto 0);
			fraude: out std_logic
			
		 );
end sodamachine; 

architecture estrutura of sodamachine is

signal tot_ld, tot_clr, tot_lt: std_logic;

  
  component partedecontrole is  
     port ( c, tot_lt, clock, reset: in std_logic; 
            velocidade: in std_logic_vector (7 downto 0);
	    d, tot_ld, tot_clr: out std_logic;
	    fraude: out std_logic		
				
		 );
  end component; 
  
  component parteoperativa is  
     port ( moeda, produto: in std_logic_vector (1 downto 0); 
            tot_ld, tot_clr, clock, reset: in std_logic;
			   tot_lt: out std_logic;
				troco: out std_logic_vector (7 downto 0)
			
		 );
  end component; 
	
begin

	
		PC: partedecontrole port map (
			c => c,
			tot_lt => tot_lt,
			clock => clock,
			reset => reset,
			velocidade => velocidade,
			d => d,
			fraude => fraude,
			tot_ld => tot_ld,
			tot_clr => tot_clr
			
		);
		
		PO: parteoperativa port map (
			moeda => moeda,
			produto => produto,
			tot_ld => tot_ld,
			tot_clr => tot_clr,
			clock => clock,
			reset => reset,
			tot_lt => tot_lt,
			troco => troco
		);
end estrutura;
