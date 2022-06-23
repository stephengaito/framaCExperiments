# Dynamic Allocation

In this experiment we explore Frama-C's ability to deal with dynamic
allocation and ways to work around Frama-C's current limitations.

At the moment (Frama-C Manganese v25.0-beta), dynamic allocation is still
*officially* experimental and incomplete. Unfortunately this is a problem
for my use of Frama-C as all of the tools I want to verify *will* make
inherent use of dynamic allocation.

**Question:** can we, by understanding Frama-C's current *implementation*,
work around these issues?

In this example I have tried to break the memory allocation using fairly
routine structures. So far *EVA* has not problem. However *WP* does not
like casts from the standard `calloc` to any variable which is not a
`void*`.

## Resources

Anyone who wants to follow this experiment *must* have read:

- section 2.7 "Pointers and physical addressing" of the
  [ACSL](https://frama-c.com/download/acsl.pdf) reference *and* its
  companion [ACSL as
  implemented](https://frama-c.com/download/frama-c-acsl-implementation.pdf)
  implemented reference.

- section 5.6 "Memory Model - Bases separation" of the
  [EVA](https://frama-c.com/download/frama-c-eva-manual.pdf) user manual.

- chapter 3 "WP Models" of the
  [WP](https://frama-c.com/download/frama-c-wp-manual.pdf) user manual. Of
  particular importance is section 3.6 "The Typed Memory Model".

- the `calloc` / `malloc` / `free` specifications in Frama-C's
  `share/libc/std.h` file.

### Other potentially useful references:

- [ACSL-by-example](https://github.com/fraunhoferfokus/acsl-by-example/blob/master/ACSL-by-Example.pdf)

## Tips and tricks...

