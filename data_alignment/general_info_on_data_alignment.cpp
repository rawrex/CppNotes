// Data structure alignment is the way data is arranged and accessed in computer memory.
// It consists of three separate but related issues:
//	- Data alignment,
//	- Data structure padding,
//	- Packing

// The CPU in modern computer hardware performs reads and writes 
// Most efficiently when the data is naturally aligned.
//
// "Natural" alignment means aligned to its own type width.
// So, the first one, Data Aliginment is the aligning of elements according to their natural alignment.
//
// To ensure natural alignment, it may be sometimes necessary to insert some padding 
// between structure elements or after the last element of a structure.
// E.g. on a 32-bit machine,
// A data structure containing a 16-bit value followed by a 32-bit value could have 16 bits of padding 
// between the 16-bit value and the 32-bit value to align the 32-bit part on a 32-bit boundary.
