# Frama-C experiments

This project consists of a collection of small experiments in the use of
the [Frama-C](https://frama-c.com) ANSI-C verification tool.

In all of these experiments I use my
[Frama-C-runner](https://github.com/diSimplex/frama-c-runner) tool to
actually run Frama-C on each example. My Frama-C-runner requires a
[`compile_commands.json`](https://clang.llvm.org/docs/JSONCompilationDatabase.html)
file which in our case is created using the
[Meson](https://mesonbuild.com/) build tool. The Frama-C-runner
definitions we are using can be found (and edited) in the `.fcrConfig`
subdirectory of the "root" directory of this project.

For each experiment I explicitly run Frama-C with only the EVA plugins
first (`fcr`). Once the EVA plugins complete with no errors, then, and
only then, I run Frama-C using the WP plugins (`fcr -fcr wp`).

The `fcr -fcr wp` Frama-C-runner configuration, `.fcrConfig/wp`, is
tailored to keep the WP plugin's [Why3](https://why3.lri.fr/) proof
obligation scripts in the `wpProofObligations` subdirectory. Reviewing
these scripts can be useful to gain an understanding of why WP may be
having problems proving the code in each experiment.

----

Our *first experiment* is how to handle the **dynamic allocation** of
pointers to typedef'ed structures. As might be used to implement lists or
graphs.

In this experiment the *EVA* plugin handles calloc quite well.
Unfortunately the *WP* plugin has lots of complaints trying to do
"obvious" ANSI-C things... which is not actually surprising as
manipulating raw C pointers is very very error prone at the best of times.
To be able to deal with this, *WP* needs to be provided with information
on *how you are actually using these pointers*.

----

Our *next experiment* is ....

