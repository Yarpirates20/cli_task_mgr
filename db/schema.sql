-- DB Name: task_mgr
-- user: postgres
-- pw: postgres
-- host: 172.29.176.1 : 5432

DROP TABLE IF EXISTS Task;
DROP TABLE IF EXISTS Category;

-- Create Category table
CREATE TABLE IF NOT EXISTS Category(
	CategoryId	INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	CategoryName TEXT NOT NULL UNIQUE

	
);

-- Create Task table
CREATE TABLE IF NOT EXISTS Task(
	TaskId		INT	GENERATED  ALWAYS AS IDENTITY   PRIMARY KEY,
	CreatedOn	TIMESTAMPTZ DEFAULT NOW(),
	TaskDesc	TEXT NOT NULL,
	DueDate		DATE ,
	Completed	BOOLEAN NOT NULL DEFAULT FALSE,
	Priority	VARCHAR(10) DEFAULT 'Normal',
	CONSTRAINT	check_priority_level_in_list CHECK (Priority
	IN('Low', 'Normal', 'High')),

	CategoryId	INT REFERENCES Category(CategoryId) ON DELETE CASCADE
);

