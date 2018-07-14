.name		"some st shit1 - 1"
.comment	"bla bla bla1 - 1"

# ld		%10, r2
# ld		%2, r3
# ld		%33554431, r15
# ld		%-1, r16

# added to the zero value;
ld		%190055938, r7
ld		%4, r10
ld		%0, r11
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

# add data	adopt fork;

# +- 10 for changing
# 1,2 + 1 = 2,3
# add only the first one;
# to the different points and then get the simultaneous;
# 2,1, 3,4 fork after -> fork jump

# 8 <-> sti + jump i need live;

#0,1 -> 1,2

# forward 2

live	%-1
fork	%8
add		r11, r10, r11
zjmp	%2
live	%-1
live	%-1
live	%-1
sti     r7, r11, %100
# synchronize
# fork	%3






