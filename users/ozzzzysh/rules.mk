TAP_DANCE_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
LEADER_ENABLE = yes

SRC += ozzzzysh.c

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
endif
