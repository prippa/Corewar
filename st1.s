.name		"some st shit1 - 1"
.comment	"bla bla bla1 - 1"

# ld		%10, r2
# ld		%2, r3
# ld		%33554431, r15
# ld		%-1, r16


# ld		%7, r10
# ld		%7, r11
# ld		%7, r12
# ld		%7, r13


# sti		r1,	%100, %100
# sti		r11,	%98, r2
# sti		r12,	%96, r2
# sti		r13,	%94, r2

# sti		r10,	%102, r2
# sti		r11,	%100, r2
# sti		r12,	%98, r2
# sti		r13,	%96, r2


fork	%3
zjmp	%1
live	%-1
fork	%5






