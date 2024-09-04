include config.mk
 
all:
	@$(MAKE) -C ./source

clean:
	@rm -rf $(BUILD_DIR)
