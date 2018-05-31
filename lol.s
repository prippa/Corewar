.name		"name"
.comment	"comment"

sti r1, %:live, %1

live:	live %1
		zjmp %:live