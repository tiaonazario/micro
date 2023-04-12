library ieee;
use ieee.std_logic_1164.all; 
use ieee.numeric_std.all;

entity partedecontrole is  
  port (   c, tot_lt, clock, reset: in std_logic;
	        velocidade: in std_logic_vector (7 downto 0);
			  d, tot_ld, tot_clr, fraude: out std_logic
	    );
end partedecontrole; 


architecture estrutura of partedecontrole is 

    type estado is (inicio, esperar, somar, fornecer);
	 
    signal atual, proximo: estado; 
	 signal velocidade_moeda: std_logic_vector (7 downto 0):=b"00000101";
	 
begin

    selecionar_estado:process (clock, reset)
	 begin 
	      if (reset = '1') then
			    atual <= inicio;
		   elsif (rising_edge(clock)) then
			    atual <= proximo;
		   end if;
	end process selecionar_estado;
	
	tot_clr <= '1' when atual = inicio else '0';
	tot_ld <= '1' when atual = somar else '0';
	d <= '1' when atual = fornecer else '0';
	
	selecionar_proximo_estado:process (c, tot_lt, atual)
	begin
		case atual is
			when inicio =>
				fraude <= '0';
				proximo <= esperar;
				
			when esperar =>
				
				if velocidade=velocidade_moeda then
						
					if c = '1' then proximo <= somar;
					elsif tot_lt = '0' then proximo <= fornecer;
					else proximo <= esperar;
					end if;
					fraude <= '0';
				else 
					fraude <= '1';
					
					proximo <= esperar;
						
				end if;
			when somar =>
				fraude <= '0';
				proximo <= esperar;
			
			when fornecer =>
				proximo <= inicio;
				fraude <= '0';
	end case;
	end process selecionar_proximo_estado;
end estrutura;
