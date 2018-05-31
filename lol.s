.name		"name"
.comment	"comment"

# sti r1, %:live, %1
ld %-1, r2

live:	live %1
		zjmp %:live