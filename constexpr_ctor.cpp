// Ctors can't be const, but ctors in a literal class can be constexpr functions
// (Recall that a literal class must provide at least one constexpr ctor)
// A constexpr ctor is used to generate objects that are constexpr
// and for parameters or return types in constexpr functions:


