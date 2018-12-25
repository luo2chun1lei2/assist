.PHONY: _top $(MAKECMDGOALS)

$(MAKECMDGOALS) _top:
	@$(MAKE) -C src --no-print-directory -rR $(MAKECMDGOALS)
