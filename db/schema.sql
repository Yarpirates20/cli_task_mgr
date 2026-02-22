-- DB Name: task_mgr
-- user: postgres
-- pw: postgres
-- host: 172.29.176.1 : 5432

DROP TABLE IF EXISTS Category;
DROP TABLE IF EXISTS Task;

-- Create Category table
CREATE TABLE IF NOT EXISTS Category(
	CategoryId	INT GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	Name		VARCHAR(30) NOT NULL

	
);

-- Create Task table
CREATE TABLE IF NOT EXISTS Task(
	TaskId		INT	GENERATED  ALWAYS AS IDENTITY   PRIMARY KEY,
	CreatedOn	TIMESTAMPTZ NOT NULL,
	TaskDesc	TEXT NOT NULL,
	DueDate		DATE NOT NULL,
	Completed	BOOLEAN NOT NULL,

	CategoryId	INT REFERENCES Category(CategoryId)
);

