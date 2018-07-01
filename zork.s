.name "zork!<>?@#$%''\\/"
.comment "I'M ALIIIIVE"

aff r3
aff r3
aff r2
aff r2
aff r11
aff r11
aff r13
aff r13
aff r4
aff r4
aff r4
aff r4
aff r4
aff r4
aff r4
aff r4
aff r16
aff r16
aff r4
aff r4
l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live

