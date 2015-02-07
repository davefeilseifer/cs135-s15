WANDER_DIR = wanderer
FOLLOW_DIR = follower
all: project_code
.PHONY: project_code

project_code:
	$(MAKE) -C $(WANDER_DIR)
	$(MAKE) -C $(FOLLOW_DIR)

clean:
	$(MAKE) -C $(WANDER_DIR) clean
	$(MAKE) -C $(FOLLOW_DIR) clean
	rm -rf $(WANDER_DIR)/bin
	rm -rf $(FOLLOW_DIR)/bin

