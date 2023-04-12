library ieee;
use ieee.std_logic_1164.all; 
use ieee.numeric_std.all;

entity sodamachine_tb is  
 
end sodamachine_tb; 

architecture estrutura of sodamachine_tb is

  component sodamachine is  
      port ( moeda, produto: in std_logic_vector (1 downto 0); 
         c, clock, reset: in std_logic;
	 velocidade: in std_logic_vector (7 downto 0);	 
	 d: out std_logic;
	 troco: out std_logic_vector (7 downto 0);
	 fraude: out std_logic
			
		 );
  end component; 
  signal moeda, produto: std_logic_vector (1 downto 0);
  signal c, d, clock, reset, fraude: std_logic;
  signal velocidade, troco: std_logic_vector (7 downto 0);

begin

  maquina: sodamachine port map(
	moeda => moeda,
	produto => produto,
	c => c,
	clock => clock,
	reset => reset,
	d => d,
	fraude => fraude,	
	velocidade => velocidade,	
	troco => troco
);
process

begin
	
    -- inicio    
    reset<='1';
	clock<='0';
	c <= '0';
	moeda <="00";
	produto <="01";
    velocidade <= "00000000";
	
	wait for 10 ns;
	reset <='0';

	-- esperar
    wait for 10 ns;
	clock<= not clock;
	c <= not c;	
	moeda <= "11";
	velocidade <= "00000101";
	wait for 10 ns;
    clock <= not clock;
	
    -- somar
	wait for 10 ns;	
	clock <= not clock;
	wait for 10 ns;
	clock <= not clock;

    -- esperar (sempre depois que faz a ultima soma do teste)
    wait for 10 ns;	
	clock <= not clock;
    c <= not c;
	wait for 10 ns;
	clock <= not clock;

    -- fornecer
    wait for 10 ns;	
	clock <= not clock;
	wait for 10 ns;
	clock <= not clock;

    -- inicio
    wait for 10 ns;	
	clock <= not clock;
	wait for 10 ns;
	clock <= not clock;

    wait;

end process;
end estrutura;
