# SortedMultiMap
Project Description:

The "Sorted Multi-Map and Iterator Testing" project is a comprehensive software development and testing initiative in C++. It focuses on the creation, testing, and validation of a custom "Sorted Multi-Map" data structure and its associated iterator. The Sorted Multi-Map is designed to store key-value pairs while maintaining a sorted order based on user-defined sorting relations. This project aims to ensure the correctness, efficiency, and robustness of the Sorted Multi-Map and validate the functionality of the provided iterator.

Key Components and Features:

Sorted Multi-Map Implementation: The project includes the development of a Sorted Multi-Map data structure capable of storing key-value pairs. The Sorted Multi-Map allows users to specify sorting relations, such as ascending or descending order based on keys. It provides functionalities for adding, removing, and searching for key-value pairs while preserving the specified sorting order.

Iterator Implementation: An iterator class is provided to facilitate the traversal of key-value pairs within the Sorted Multi-Map. The iterator enables forward iteration through the elements, ensuring they are visited in the correct order according to the sorting relation defined by the user.

Custom Sorting Relations: The project offers a set of predefined sorting relations, including ascending, descending, and relations based on key properties (e.g., sum of digits). Users can choose the appropriate sorting relation for their specific use case.

Testing Suite:

The project incorporates a comprehensive testing suite designed to thoroughly evaluate the correctness and performance of the Sorted Multi-Map and iterator implementations. The testing suite includes the following test cases:

Creation and Initialization: Tests the creation of an empty Sorted Multi-Map and validates its initial state, including size and emptiness.

Search Functionality: Evaluates the search functionality by adding key-value pairs to the Sorted Multi-Map and verifying that search operations return the expected results, considering the specified sorting relation.

Remove Functionality: Tests the removal of key-value pairs from the Sorted Multi-Map and ensures that the correct pairs are removed based on the sorting relation.

Iterator Functionality: Validates the functionality of the iterator by testing its ability to traverse key-value pairs within the Sorted Multi-Map in the expected order. Correctness in element retrieval and iterator validity are confirmed.

Custom Sorting Relations: Extensive testing of key-value pairs using different custom sorting relations, including those based on key properties.

Project Goals:

The primary objectives of this project are as follows:

To create a reliable and efficient Sorted Multi-Map data structure capable of handling key-value pairs and maintaining a sorted order based on user-defined relations.

To implement a functional iterator that allows for the correct traversal of key-value pairs within the Sorted Multi-Map.

To extensively test the Sorted Multi-Map and iterator to ensure correctness and performance across various scenarios, including custom sorting relations.

To provide users with a versatile data structure and testing framework that can be integrated into various C++ projects requiring sorted key-value storage and iteration.

By achieving these goals, this project offers a dependable Sorted Multi-Map data structure and iterator that can serve as a valuable component in a wide range of software applications. Additionally, it demonstrates best practices for data structure development and testing in C++.
