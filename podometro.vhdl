library ieee;
use ieee. std_logic_1164.all;
use ieee. std_logic_unsigned.all;
use ieee.numeric_std.all;

entity podometro is 
port(
	clock: inout std_logic;
	clr: in std_logic;
	push1: in std_logic;  
	push2: in std_logic;
	d1: inout std_logic_vector(3 downto 0);
	d2: inout std_logic_vector(3 downto 0);
	d3: inout std_logic_vector(3 downto 0);
	d4: inout std_logic_vector(3 downto 0);
	d: inout std_logic_vector(3 downto 0);
	
	selector: out std_logic_vector(3 downto 0);
	display: out std_logic_vector(7 downto 0));
end podometro; 

architecture arq of podometro is
begin

contador:process(clock,push1,push2,clr) is
	variable ban:std_logic:='1';
	variable sel_variable:integer:=0;	
	begin 
	
		if(CLOCK'EVENT and CLOCK='1')then 
		
			if(clr='1')then
				d4<="0000";
				d3<="0000";
				d2<="0000";
				d1<="0000";
			else
		
				if(push1='1' or push2='1')then
					if(ban='1')then 
						ban:='0';
						if(d4<9)then
							d4<=d4+1;
						else
							d4<="0000";
							if(d3<9)then
								d3<=d3+1;
							else
								d3<="0000";
								if(d2<9)then
									d2<=d2+1;
								else
									d2<="0000";
									if(d1<9)then
										d1<=d1+1;
									else
										d4<="";
										d3<="";
										d2<="";
										d1<="";
									end if;
								end if;
							end if;
							
						end if;
					
					end if;
				
				elsif(push1='0' or push2='0')then
					ban:='1';
				end if;
			end if;

			if(sel_variable=5)then
				sel_variable:=1;
			else
				sel_variable:=sel_variable+1;
			end if;
			 
			case sel_variable is
				when 1 => 
					selector <= "0111";
					d <= d1;
				when 2 => 
					selector <= "1011";
					d <= d2;
				when 3 => 
					selector<= "1101";
					d <= d3;
				when others => 
					selector <="1110";
					d <= d4;
			end case;
		end if;
end process contador;

disp1:process(d) is
begin
		case d is
			when "0000" => display <= "11111100";
			when "0001" => display <= "01100000";
			when "0010" => display <= "11011010";
			when "0011" => display <= "11110010";
			when "0100" => display <= "01100110";
			when "0101" => display <= "10110110";
			when "0110" => display <= "10111110";
			when "0111" => display <= "11100000";
			when "1000" => display <= "11111110";
			when others => display <= "11110110";
		end case;

end process disp1;
	

end arq;