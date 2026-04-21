# ICU - International Components for Unicode

ICU is a set of cross-platform Unicode-based globalization C/C++ libraries.
For more information see:

http://site.icu-project.org/

This repository contains the original ICU libraries source code overlaid with
the build2-based build system and packaged for the build2 package manager
(bpkg).

The build2-based development setup for ICU uses two build configurations: a
host configuration for the ICU tools and a target configuration for the
libraries. For example:

```
git clone .../icu.git
cd icu

bdep init --empty

bdep config create @host   ../icu-host --type host cc config.cxx=g++
bdep config create @target ../icu-target cc config.cxx=g++

bdep init @host -d icu-tools
bdep init @target -d libicuuc -d libicui18n -d libicuio
```
