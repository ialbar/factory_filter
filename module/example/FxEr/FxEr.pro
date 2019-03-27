TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../source/create_filters.c \
    ../../source/f1er.c \
    ../../source/f1er_highpass.c \
    ../../source/f1er_lowpass.c \
    ../../source/f2er.c \
    ../../source/f2er_bandpass.c \
    ../../source/f2er_highpass.c \
    ../../source/f2er_lowpass.c \
    ../../source/factory_f1er.c \
    ../../source/factory_f1er_high_pass.c \
    ../../source/factory_f1er_low_pass.c \
    ../../source/factory_f2er.c \
    ../../source/factory_f2er_band_pass.c \
    ../../source/factory_f2er_high_pass.c \
    ../../source/factory_f2er_low_pass.c \
    ../../source/factory_fsos.c \
    ../../source/fsos.c \
    ../../source/fsos_nth_order.c \
    ../main.c

HEADERS += \
    ../../include/create_filters.h \
    ../../include/f1er.h \
    ../../include/f1er_highpass.h \
    ../../include/f1er_lowpass.h \
    ../../include/f2er.h \
    ../../include/f2er_bandpass.h \
    ../../include/f2er_highpass.h \
    ../../include/f2er_lowpass.h \
    ../../include/factory_f1er.h \
    ../../include/factory_f1er_high_pass.h \
    ../../include/factory_f1er_low_pass.h \
    ../../include/factory_f2er.h \
    ../../include/factory_f2er_band_pass.h \
    ../../include/factory_f2er_high_pass.h \
    ../../include/factory_f2er_low_pass.h \
    ../../include/factory_fsos.h \
    ../../include/fsos.h \
    ../../include/fsos_nth_order.h
