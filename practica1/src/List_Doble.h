#include "Nodo.cpp"

template <class T>
    class dll_t {
    private:
        dll_node_t<T>* head_;
        dll_node_t<T>* tail_;
        int sz_;

    public:
        dll_t(void);
   
        virtual ~dll_t(void); 

	      void insert_tail(dll_node_t<T>*);

        void insert_head(dll_node_t<T>*);

        dll_node_t<T>* extract_tail(void);

        dll_node_t<T>* extract_head(void);

        dll_node_t<T>* get_tail(void);

        dll_node_t<T>* get_head(void);

        bool empty(void);

        void remove(dll_node_t<T>*);

        int get_size(void);

        ostream& write(ostream& os);
    };
