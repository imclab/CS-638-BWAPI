#pragma once
/*
 * DebugFlags.h
 */
#include "Manager.h"


class DebugFlags
{
private:
	bool drawNone;          // Draw no debug screen info, overriding other flags
	bool drawSystemDetails; // Draw details for managers and some advisors 

	bool drawSquadDetails;  // Draw squad debug details

	bool drawAgentDetails;  // Draw (state, owning mgr, target) for each agent
	bool drawAgentTargets;  // Draw lines to each agents current targets

	bool drawBuildQueue;    // Draw the BuildManager's current queue
	bool drawBuildStack;    // Draw the BuildManager's current stack

public:
	friend class Manager;

	enum Flag
	{ 
		none, 
		system_details,
		squad_details,
		agent_details, 
		agent_targets, 
		build_queue, 
		build_stack, 
		NUM_FLAGS
	};

	static DebugFlags& instance() { static DebugFlags df; return df; }

	void draw();

	bool getFlag(const Flag& flag) const;
	void setFlag(const Flag& flag, const bool state);
	void toggleFlag(const Flag& flag);

private:
	// DebugFlags is singleton, hence private ctors/assignment
	DebugFlags();
	DebugFlags(const DebugFlags& other);
	void operator=(const DebugFlags& other);	
};
