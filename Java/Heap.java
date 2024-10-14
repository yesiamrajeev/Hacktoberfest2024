import java.util.ArrayList;

// Generic Heap class that supports both Max-Heap and Min-Heap functionalities
class Heap<T extends Comparable<T>> {
  private final ArrayList<T> maxHeap; // Max-Heap storage
  private final ArrayList<T> minHeap; // Min-Heap storage

  // Constructor to initialize the heaps
  public Heap() {
    maxHeap = new ArrayList<>();
    minHeap = new ArrayList<>();
  }

  public static void main(String[] args) throws Exception {
    Heap<Integer> heap = new Heap<>();

    // Inserting elements into the Max-Heap
    heap.insertInMaxHeap(34);
    heap.insertInMaxHeap(21);
    heap.insertInMaxHeap(4);
    heap.insertInMaxHeap(3);
    heap.insertInMaxHeap(67);
    heap.insertInMaxHeap(23);
    heap.insertInMaxHeap(65);

    // Inserting elements into the Min-Heap
    heap.insertInMinHeap(34);
    heap.insertInMinHeap(21);
    heap.insertInMinHeap(4);
    heap.insertInMinHeap(3);
    heap.insertInMinHeap(67);
    heap.insertInMinHeap(23);
    heap.insertInMinHeap(65);

    // Sorting both heaps
    ArrayList<Integer> sortedMaxHeap = heap.heapSortForMaxHeap();
    ArrayList<Integer> sortedMinHeap = heap.heapSortForMinHeap();

    // Displaying sorted heaps
    System.out.println("Max-Heap Sorted: " + sortedMaxHeap);
    System.out.println("Min-Heap Sorted: " + sortedMinHeap);
  }

  // Swaps elements at index i and j in the given list
  private void swap(ArrayList<T> list, int i, int j) {
    T temp = list.get(i);
    list.set(i, list.get(j));
    list.set(j, temp);
  }

  // Helper methods to get the parent, left child, and right child indices
  private int parent(int i) {
    return (i - 1) / 2;
  }

  private int leftChild(int i) {
    return 2 * i + 1;
  }

  private int rightChild(int i) {
    return 2 * i + 2;
  }

  // Inserts an element into the Max-Heap
  public void insertInMaxHeap(T value) {
    maxHeap.add(value);
    upHeap(maxHeap, maxHeap.size() - 1, true);
  }

  // Inserts an element into the Min-Heap
  public void insertInMinHeap(T value) {
    minHeap.add(value);
    upHeap(minHeap, minHeap.size() - 1, false);
  }

  // Performs the up-heap operation to maintain the heap property
  private void upHeap(ArrayList<T> list, int i, boolean isMaxHeap) {
    if (i == 0) return; // Base case: reached the root

    int p = parent(i);
    if ((isMaxHeap && list.get(i).compareTo(list.get(p)) > 0)
        || (!isMaxHeap && list.get(i).compareTo(list.get(p)) < 0)) {
      swap(list, i, p);
      upHeap(list, p, isMaxHeap); // Recursively heapify the parent
    }
  }

  // Removes the root element from the Max-Heap
  public T removeInMaxHeap() throws Exception {
    return remove(maxHeap, true);
  }

  // Removes the root element from the Min-Heap
  public T removeInMinHeap() throws Exception {
    return remove(minHeap, false);
  }

  // Removes the root element and re-heapifies the list
  private T remove(ArrayList<T> list, boolean isMaxHeap) throws Exception {
    if (list.isEmpty()) throw new Exception("Heap is empty");
    T root = list.get(0);
    T last = list.remove(list.size() - 1);

    if (!list.isEmpty()) {
      list.set(0, last); // Move last element to root
      downHeap(list, 0, isMaxHeap); // Heapify the root
    }
    return root;
  }

  // Performs the down-heap operation to maintain the heap property
  private void downHeap(ArrayList<T> list, int i, boolean isMaxHeap) {
    int l = leftChild(i);
    int r = rightChild(i);
    int extreme = i;

    if (l < list.size()
        && ((isMaxHeap && list.get(l).compareTo(list.get(extreme)) > 0)
            || (!isMaxHeap && list.get(l).compareTo(list.get(extreme)) < 0))) {
      extreme = l;
    }

    if (r < list.size()
        && ((isMaxHeap && list.get(r).compareTo(list.get(extreme)) > 0)
            || (!isMaxHeap && list.get(r).compareTo(list.get(extreme)) < 0))) {
      extreme = r;
    }

    if (extreme != i) {
      swap(list, i, extreme);
      downHeap(list, extreme, isMaxHeap); // Recursively heapify the subtree
    }
  }

  // Heap sorts the Max-Heap and returns a sorted list
  public ArrayList<T> heapSortForMaxHeap() throws Exception {
    return heapSort(maxHeap, true);
  }

  // Heap sorts the Min-Heap and returns a sorted list
  public ArrayList<T> heapSortForMinHeap() throws Exception {
    return heapSort(minHeap, false);
  }

  // General heap sort method for both Max-Heap and Min-Heap
  private ArrayList<T> heapSort(ArrayList<T> list, boolean isMaxHeap) throws Exception {
    ArrayList<T> sortedList = new ArrayList<>();
    while (!list.isEmpty()) {
      sortedList.add(remove(list, isMaxHeap));
    }
    return sortedList;
  }
}
