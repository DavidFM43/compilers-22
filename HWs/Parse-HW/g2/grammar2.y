%%
P: S 
 | S P;
S: "if" E "then" S 
 | "if" E "then" S "else" S
 | "while" E S
 | "begin" P "end"
 | "print" E
 | E;
E: "id"
 | "integer"
 | E "+" E;
