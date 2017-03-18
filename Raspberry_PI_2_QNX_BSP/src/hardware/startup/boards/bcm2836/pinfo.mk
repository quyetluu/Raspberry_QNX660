define PINFO
PINFO DESCRIPTION=R_CarW2H Cortex-A7 startup
endef
PADDR_SIZE = $(firstword $(filter 64, $(VARIANTS)))
LIB_VARIANT = $(subst .64,,$(subst .o,,a.$(COMPOUND_VARIANT))$(PSTAG_$(PADDR_SIZE)))
