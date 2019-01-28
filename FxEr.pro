TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    f1er.c \
    factory_f1er.c \
    f1er_lowpass.c \
    factory_f1er_low_pass.c \
    f2er.c \
    factory_f2er.c \
    factory_f2er_low_pass.c \
    f2er_lowpass.c \
    factory_f2er_band_pass.c \
    f2er_bandpass.c \
    factory_f2er_high_pass.c \
    f2er_highpass.c \
    fsos.c \
    factory_fsos.c \
    fsos_nth_order.c \
    factory_f1er_high_pass.c \
    f1er_highpass.c \
    create_filters.c

HEADERS += \
    f1er.h \
    factory_f1er.h \
    f1er_lowpass.h \
    factory_f1er_low_pass.h \
    f2er.h \
    factory_f2er.h \
    factory_f2er_low_pass.h \
    f2er_lowpass.h \
    f2er_bandpass.h \
    factory_f2er_band_pass.h \
    factory_f2er_high_pass.h \
    f2er_highpass.h \
    fsos.h \
    factory_fsos.h \
    fsos_nth_order.h \
    factory_f1er_high_pass.h \
    f1er_highpass.h \
    create_filters.h
