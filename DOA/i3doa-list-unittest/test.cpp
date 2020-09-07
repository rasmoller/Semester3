#include "pch.h"
#include "../i3doa-list/linkedlist.h"
#include "../i3doa-list/VectorList.h"

class ListTest : public testing::Test
{
protected:

	List<int>* uut;

	void SetUp()
	{
		uut = new LinkedList<int>();
		//uut = new VectorList<int>();
	}

	void TearDown()
	{
		delete uut;
	}

	
};


TEST_F(ListTest, Ctor_SizeCorrect)
{
	ASSERT_EQ(0, uut->length());
}


TEST_F(ListTest, HeadInsert_HeadInsertTwo_ContentsAndLengthOK)
{
	uut->headInsert(10);
	uut->headInsert(20);

	ASSERT_EQ(2, uut->length());
	ASSERT_EQ(20, uut->at(0));
	ASSERT_EQ(10, uut->at(1));
}

TEST_F(ListTest, HeadRemove_HeadInsertTwoRemoveOne_ContentsAndLengthOK)
{
	uut->headInsert(10);
	uut->headInsert(20);
	uut->headRemove();
	ASSERT_EQ(1, uut->length());
	ASSERT_EQ(10, uut->at(0));
}

TEST_F(ListTest, HeadRemove_HeadInsertOneRemoveOne_ListIsEmpty)
{
	uut->headInsert(10);
	uut->headRemove();
	ASSERT_EQ(0, uut->length());
}

TEST_F(ListTest, HeadRemove_InsertTwoRemoveTwo_ListIsEmpty)
{
	uut->headInsert(10);
	uut->headInsert(20);
	uut->headRemove();
	uut->headRemove();

	ASSERT_EQ(0, uut->length());
}

TEST_F(ListTest, Clear_TwoElementsInList_ListLengthOK)
{
	uut->headInsert(10);
	uut->headInsert(20);
	uut->clear();

	ASSERT_EQ(0, uut->length());
}

TEST_F(ListTest, Insert_FirstElement_ContentsAndLengthOK)
{
	uut->headInsert(10);
	uut->headInsert(20);
	uut->insert(30, 0);

	ASSERT_EQ(3, uut->length());

	ASSERT_EQ(30, uut->at(0));
	ASSERT_EQ(20, uut->at(1));
	ASSERT_EQ(10, uut->at(2));
}


TEST_F(ListTest, Insert_LastElement_ContentsAndLengthOK)
{
	uut->headInsert(10);
	uut->headInsert(20);
	uut->insert(30, 2);

	ASSERT_EQ(3, uut->length());

	ASSERT_EQ(20, uut->at(0));
	ASSERT_EQ(10, uut->at(1));
	ASSERT_EQ(30, uut->at(2));
}

TEST_F(ListTest, Insert_InvalidIndex_ExceptionThrown)
{
	uut->headInsert(10);
	uut->headInsert(20);
	ASSERT_THROW(
		uut->insert(30, 3),
		std::out_of_range
	);
}



TEST_F(ListTest, Remove_FirstElement_ContentsAndLengthOK)
{
	uut->headInsert(10);
	uut->headInsert(20);
	uut->headInsert(30);
	uut->remove(0);

	ASSERT_EQ(2, uut->length());

	ASSERT_EQ(20, uut->at(0));
	ASSERT_EQ(10, uut->at(1));
}

TEST_F(ListTest, Remove_LastElement_ContentsAndLengthOK)
{
	uut->headInsert(10);
	uut->headInsert(20);
	uut->headInsert(30);
	uut->remove(2);

	ASSERT_EQ(2, uut->length());

	ASSERT_EQ(30, uut->at(0));
	ASSERT_EQ(20, uut->at(1));
}


TEST_F(ListTest, Remove_Invalidindex_ExceptionThrown)
{
	uut->headInsert(10);
	uut->headInsert(20);
	uut->headInsert(30);
	ASSERT_THROW(
		uut->remove(3),
		std::out_of_range
	);
}

TEST_F(ListTest, Indexing_IndexOutOfRange_ExceptionThrown)
{
	uut->headInsert(10);
	ASSERT_THROW(
		uut->at(2),
		std::out_of_range
	);
}

