library ieee;
use ieee. std_logic_1164.all;
use ieee. std_logic_unsigned.all;
use ieee.numeric_std.all;

entity p4 is 
port(
	clock: inout std_logic;
	clr: in std_logic;
	push1: in std_logic; 
	push2: in std_logic;
	selector: out std_logic_vector(3 downto 0);
	display: out std_logic_vector(7 downto 0));
end p4; 

architecture ap4 of p4 is
begin
	process(clock) is
	
	variable cont_var:integer:=0;
	variable cont_final:integer:=0;
	variable ban:std_logic:='1';
	variable sel_variable:integer:=0;	
	
	variable dig4:integer:=0;
	variable dig2:integer:=0;
	variable dig3:integer:=0;
	variable dig1:integer:=0;
	
	begin 
	
		if(CLOCK'EVENT and CLOCK='1')then 
		
			if(clr='1')then
				cont_var:=0;
			end if;
		
			if(push1='1')then
				
				if(ban='1')then 
					cont_var:=cont_var+1;
					ban:='0';
					
					if(cont_var<10)then
						dig4:=cont_var;
					else
						dig4:=0;
						cont_var:=0;
						if(dig3<10)then
							dig3:=dig3+1;
						else
							dig3:=0;
							if(dig2<10)then
								dig2:=dig2+1;
							else
								dig2:=0;
								dig1:=dig1+1;
							end if;
						end if;
						
					end if;	
					
				end if;
				
			elsif(push1='0')then
				ban:='1';
			end if;
			
			if(sel_variable=5)then
				sel_variable:=1;
			else
				sel_variable:=sel_variable+1;
			end if;
			
			case sel_variable is
				when 1 => 
					selector <= "0111";
					cont_final := dig1;
				when 2 => 
					selector <= "1011";
					cont_final := dig2;
				when 3 => 
					selector<= "1101";
					cont_final := dig3;
				when others => 
					selector <="1110";
					cont_final := dig4;
			end case;
				
			case cont_final is
				when 0 => display <= "11111100";
				when 1 => display <= "01100000";
				when 2 => display <= "11011010";
				when 3 => display <= "11110010";
				when 4 => display <= "01100110";
				when 5 => display <= "10110110";
				when 6 => display <= "10111110";
				when 7 => display <= "11100000";
				when 8 => display <= "11111110";
				when others => display <= "11110110";
			end case;
			
		end if; 
		
	end process;
	
	

end ap4;