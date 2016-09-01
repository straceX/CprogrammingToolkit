#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TOKEN_IDENTIFIER			1
#define TOKEN_OPERATOR_PLUS			2
#define TOKEN_OPERATOR_MINUS		3
#define TOKEN_OPERATOR_MULTIPLY		4
#define TOKEN_OPERATOR_DIVIDE		5
#define TOKEN_LEFT_PARANTHESIS		6
#define TOKEN_RIGHT_PARANTHESIS		7
#define TOKEN_ASSIGNMENT			8
#define TOKEN_SEMICOLON				9


#define MAX_TOKEN					512
#define BLANK						0x01
#define NEWLINE						0x02
#define ALPHA						0x04



char	g_prog[4096 + 1];		
char	*g_cp;					
char	*g_limit;				
int		g_lineNo;

char g_token[MAX_TOKEN];
char *g_tokenTypes[] = { "", "Identifier", "Operatör Plus", "Operator Minus", "Operetor Multiply", "Operator Divide", "Operator Left Paranthesis", "Operator Right Paranthesis", "Operator Assignment", "Delimiter Semicolon" };


static unsigned char g_cmap[256] = {
	/* 000 nul */	0,
	/* 001 soh */	0,
	/* 002 stx */	0,
	/* 003 etx */	0,
	/* 004 eot */	0,
	/* 005 enq */	0,
	/* 006 ack */	0,
	/* 007 bel */	0,
	/* 010 bs  */	0,
	/* 011 ht  */	BLANK,
	/* 012 nl  */	BLANK | NEWLINE,
	/* 013 vt  */	BLANK,
	/* 014 ff  */	BLANK,
	/* 015 cr  */	0,
	/* 016 so  */	0,
	/* 017 si  */	0,
	/* 020 dle */	0,
	/* 021 dc1 */	0,
	/* 022 dc2 */	0,
	/* 023 dc3 */	0,
	/* 024 dc4 */	0,
	/* 025 nak */	0,
	/* 026 syn */	0,
	/* 027 etb */	0,
	/* 030 can */	0,
	/* 031 em  */	0,
	/* 032 sub */	0,
	/* 033 esc */	0,
	/* 034 fs  */	0,
	/* 035 gs  */	0,
	/* 036 rs  */	0,
	/* 037 us  */	0,
	/* 040 sp  */	BLANK,
	/* 041 !   */	0,
	/* 042 "   */	0,
	/* 043 #   */	0,
	/* 044 $   */	0,
	/* 045 %   */	0,
	/* 046 &   */	0,
	/* 047 '   */	0,
	/* 050 (   */	0,
	/* 051 )   */	0,
	/* 052 *   */	0,
	/* 053 +   */	0,
	/* 054 ,   */	0,
	/* 055 -   */	0,
	/* 056 .   */	0,
	/* 057 /   */	0,
	/* 060 0   */	0,
	/* 061 1   */	0,
	/* 062 2   */	0,
	/* 063 3   */	0,
	/* 064 4   */	0,
	/* 065 5   */	0,
	/* 066 6   */	0,
	/* 067 7   */	0,
	/* 070 8   */	0,
	/* 071 9   */	0,
	/* 072 :   */	0,
	/* 073 ;   */	0,
	/* 074 <   */	0,
	/* 075 =   */	0,
	/* 076 >   */	0,
	/* 077 ?   */	0,
	/* 100 @   */	0,
	/* 101 A   */	ALPHA,
	/* 102 B   */	ALPHA,
	/* 103 C   */	ALPHA,
	/* 104 D   */	ALPHA,
	/* 105 E   */	ALPHA,
	/* 106 F   */	ALPHA,
	/* 107 G   */	ALPHA,
	/* 110 H   */	ALPHA,
	/* 111 I   */	ALPHA,
	/* 112 J   */	ALPHA,
	/* 113 K   */	ALPHA,
	/* 114 L   */	ALPHA,
	/* 115 M   */	ALPHA,
	/* 116 N   */	ALPHA,
	/* 117 O   */	ALPHA,
	/* 120 P   */	ALPHA,
	/* 121 Q   */	ALPHA,
	/* 122 R   */	ALPHA,
	/* 123 S   */	ALPHA,
	/* 124 T   */	ALPHA,
	/* 125 U   */	ALPHA,
	/* 126 V   */	ALPHA,
	/* 127 W   */	ALPHA,
	/* 130 X   */	ALPHA,
	/* 131 Y   */	ALPHA,
	/* 132 Z   */	ALPHA,
	/* 133 [   */	0,
	/* 134 \   */	0,
	/* 135 ]   */	0,
	/* 136 ^   */	0,
	/* 137 _   */	ALPHA,
	/* 140 `   */	0,
	/* 141 a   */	ALPHA,
	/* 142 b   */	ALPHA,
	/* 143 c   */	ALPHA,
	/* 144 d   */	ALPHA,
	/* 145 e   */	ALPHA,
	/* 146 f   */	ALPHA,
	/* 147 g   */	ALPHA,
	/* 150 h   */	ALPHA,
	/* 151 i   */	ALPHA,
	/* 152 j   */	ALPHA,
	/* 153 k   */	ALPHA,
	/* 154 l   */	ALPHA,
	/* 155 m   */	ALPHA,
	/* 156 n   */	ALPHA,
	/* 157 o   */	ALPHA,
	/* 160 p   */	ALPHA,
	/* 161 q   */	ALPHA,
	/* 162 r   */	ALPHA,
	/* 163 s   */	ALPHA,
	/* 164 t   */	ALPHA,
	/* 165 u   */	ALPHA,
	/* 166 v   */	ALPHA,
	/* 167 w   */	ALPHA,
	/* 170 x   */	ALPHA,
	/* 171 y   */	ALPHA,
	/* 172 z   */	ALPHA,
};