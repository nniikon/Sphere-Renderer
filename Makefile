include config.mk
 
all:
	@$(MAKE) -C ./source
	$(GXX) $(BUILD_DIR)/*.o -o $(BUILD_DIR)/$(EXEC_NAME) $(CFLAGS)

run:
	$(BUILD_DIR)/$(EXEC_NAME)

clean:
	@rm -rf $(BUILD_DIR)
