/* -*- sh -*- */

/*
 * Linker script for i386 images
 *
 */

SECTIONS {

    /* Each section starts at a virtual address of zero.
     *
     * We guarantee alignment of virtual addresses to any alignment
     * specified by the constituent object files (e.g. via
     * __attribute__((aligned(x)))).  Load addresses are guaranteed
     * only up to _max_align.  Provided that all loader and relocation
     * code honours _max_align, this means that physical addresses are
     * also guaranteed up to _max_align.
     *
     * Note that when using -DKEEP_IT_REAL, the UNDI segments are only
     * guaranteed to be loaded on a paragraph boundary (i.e. 16-byte
     * alignment).  Using _max_align>16 will therefore not guarantee
     * >16-byte alignment of physical addresses when -DKEEP_IT_REAL is
     * used (though virtual addresses will still be fully aligned).
     *
     */

    PROVIDE ( _max_align = 16 );

    /*
     * The prefix
     *
     */

    .prefix 0x0 : AT ( _prefix_lma ) {
	_prefix = .;
	*(.prefix)
	*(.prefix.*)
	_mprefix = .;
    } .bss.prefix (NOLOAD) : AT ( _end_lma ) {
	_eprefix = .;
    }
    _prefix_filesz	= ABSOLUTE ( _mprefix - _prefix );
    _prefix_memsz	= ABSOLUTE ( _eprefix - _prefix );

    /*
     * The 16-bit (real-mode) code section
     *
     */

    .text16.early 0x0 : AT ( _text16_early_lma ) {
	_text16 = .;
	*(.text16.null)
	. += 1;				/* Prevent NULL being valid */
	*(.text16.early)
	*(.text16.early.*)
	_etext16_early = .;
    } .text16.late ALIGN ( _max_align ) : AT ( _text16_late_lma ) {
	_text16_late = .;
	*(.text16)
	*(.text16.*)
	_mtext16 = .;
    } .bss.text16 (NOLOAD) : AT ( _end_lma ) {
	_etext16 = .;
    }
    _text16_early_filesz = ABSOLUTE ( _etext16_early - _text16 );
    _text16_early_memsz	= ABSOLUTE ( _etext16_early - _text16 );
    _text16_late_filesz	= ABSOLUTE ( _mtext16 - _text16_late );
    _text16_late_memsz	= ABSOLUTE ( _etext16 - _text16_late );
    _text16_memsz	= ABSOLUTE ( _etext16 - _text16 );

    /*
     * The 16-bit (real-mode) data section
     *
     */

    .data16 0x0 : AT ( _data16_lma ) {
	_data16 = .;
	. += 1;				/* Prevent NULL being valid */
	*(.rodata16)
	*(.rodata16.*)
	*(.data16)
	*(.data16.*)
	_mdata16 = .;
    } .bss.data16 (NOLOAD) : AT ( _end_lma ) {
	*(.bss16)
	*(.bss16.*)
	*(.stack16)
	*(.stack16.*)
	_edata16 = .;
    }
    _data16_filesz	= ABSOLUTE ( _mdata16 - _data16 );
    _data16_memsz	= ABSOLUTE ( _edata16 - _data16 );

    /*
     * The 32-bit sections
     *
     */

    .textdata 0x0 : AT ( _textdata_lma ) {
	_textdata = .;
	*(.text.null_trap)
	. += 1;				/* Prevent NULL being valid */
	*(.text)
	*(.text.*)
	*(.rodata)
	*(.rodata.*)
	*(.data)
	*(.data.*)
	*(SORT(.tbl.*))		/* Various tables.  See include/tables.h */
	_mtextdata = .;
    } .bss.textdata (NOLOAD) : AT ( _end_lma ) {
	*(.bss)
	*(.bss.*)
	*(COMMON)
	*(.stack)
	*(.stack.*)
	_etextdata = .;
    }
    _textdata_filesz	= ABSOLUTE ( _mtextdata - _textdata );
    _textdata_memsz	= ABSOLUTE ( _etextdata - _textdata );

    /*
     * Compressor information block
     *
     */

    .zinfo 0x0 : AT ( _zinfo_lma ) {
	_zinfo = .;
	*(.zinfo)
	*(.zinfo.*)
	_mzinfo = .;
    } .bss.zinfo (NOLOAD) : AT ( _end_lma ) {
	_ezinfo = .;
    }
    _zinfo_filesz	= ABSOLUTE ( _mzinfo - _zinfo );
    _zinfo_memsz	= ABSOLUTE ( _ezinfo - _zinfo );

    /*
     * Weak symbols that need zero values if not otherwise defined
     *
     */

    .weak 0x0 : AT ( _end_lma ) {
	_weak = .;
	*(.weak)
	_eweak = .;
    }
    _assert = ASSERT ( ( _weak == _eweak ), ".weak is non-zero length" );

    /*
     * Dispose of the comment and note sections to make the link map
     * easier to read
     *
     */

    /DISCARD/ : {
	*(.comment)
	*(.comment.*)
	*(.note)
	*(.note.*)
	*(.eh_frame)
	*(.eh_frame.*)
	*(.rel)
	*(.rel.*)
	*(.discard)
    }

    /*
     * Load address calculations.  In older versions of ld, ALIGN()
     * can operate only on the location counter, so we use that.
     *
     */

    .			= 0;

    .			= ALIGN ( _max_align );
    _prefix_lma		= .;
    .			+= _prefix_filesz;

    .			= ALIGN ( _max_align );
    _text16_early_lma	= .;
    .			+= _text16_early_filesz;

    .			= ALIGN ( _max_align );
    _payload_lma	= .;
    _text16_late_lma	= .;
    .			+= _text16_late_filesz;

    .			= ALIGN ( _max_align );
    _data16_lma		= .;
    .			+= _data16_filesz;

    .			= ALIGN ( _max_align );
    _textdata_lma	= .;
    .			+= _textdata_filesz;

    _filesz		= .; /* Do not include zinfo block in file size */

    .			= ALIGN ( _max_align );
    _zinfo_lma		= .;
    .			+= _zinfo_filesz;

    .			= ALIGN ( _max_align );
    _end_lma		= .;

    /*
     * Values calculated to save code from doing it
     *
     */
    _text16_memsz_pgh	= ( ( _text16_memsz + 15 ) / 16 );
    _data16_memsz_pgh	= ( ( _data16_memsz + 15 ) / 16 );
    _textdata_memsz_pgh	= ( ( _textdata_memsz + 15 ) / 16 );
    _textdata_memsz_kb	= ( ( _textdata_memsz + 1023 ) / 1024 );
}
