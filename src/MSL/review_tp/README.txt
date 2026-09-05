TP MSL reference snapshot
==========================

This directory is copied from:

  other_decomp_projects/tp/libs/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/

The files are a temporary reference/staging area. They are not listed in
REXE01 splits.txt and are not compiled by the project.

The intended migration is:

1. Review a module against REXE01 assembly and sibling sources.
2. Port the compatible implementation into the normal `src/MSL/*.c` file.
3. Adapt project headers and ABI details there rather than importing TP headers
   globally.
4. Run strict function checks and the normal build/hash checks.
5. Delete the corresponding staging copy once the module is integrated.

Do not replace active `src/MSL` files or promote these files wholesale without
checking REXE01 assembly, ABI, data layouts, and auto-unit ownership. TP is the
primary reference because it contains a complete Wii-era MSL implementation;
Petari and AF e+ remain useful cross-checks for version differences.
