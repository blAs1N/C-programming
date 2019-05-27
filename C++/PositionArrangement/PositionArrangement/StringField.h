#pragma once

#ifndef __STRING_FIELD__
#define __STRING_FIELD__

namespace StringField {
	using cstring = const char*;

	static cstring INTRO = "�ڸ� ��ġ ���α׷�";
	static cstring END = "���α׷� ����";
	static cstring SELECT = "1 : ��ġ, 2 : ���, 3 : �����Ͽ� ����, 4 : �л� �߰�, 5 : �л� ����, 0 : ����. ";
	static cstring ADD_STUDENT = "�߰��� �л��� �̸��� �Է��ϼ���. ";
	static cstring DEL_STUDENT = "������ �л��� �̸��� �Է��ϼ���. ";
	static cstring START_ARRANGE = "�ڸ��� ��ġ�մϴ�";
	static cstring END_ARRANGE = "��ġ�� �Ϸ�Ǿ����ϴ�";
	static cstring FILE_ERROR = "������ �� �� �����ϴ�";
	static cstring NULL_POS = "���� �ڸ�";
}

#endif