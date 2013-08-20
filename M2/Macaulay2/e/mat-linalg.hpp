// Copyright 2013  Michael E. Stillman

#ifndef _mat_linalg_hpp_
#define _mat_linalg_hpp_

/**
 * \ingroup matrices
 */

#include "exceptions.hpp"
#include "dmat.hpp"

#ifdef HAVE_FFLAS_FFPACK
#include "aring-zzp-ffpack.hpp"
typedef M2::ARingZZpFFPACK ZZpFFPACK;
#define DMatZZpFFPACK DMat<ZZpFFPACK> 
#endif

#ifdef HAVE_FLINT
#include "aring-zz-flint.hpp"
#include "aring-zzp-flint.hpp"
typedef DMat<M2::ARingZZ> DMatZZ;
typedef DMat<M2::ARingQQFlint> DMatQQFlint;
typedef DMat<M2::ARingZZpFlint> DMatZZpFlint;
#endif

#ifdef use_new_RRR
  typedef DMat<M2::ARingRRR> DMatRRR; 
#else 
#include "coeffrings.hpp"
  typedef DMat<CoefficientRingRRR> DMatRRR;
#endif

typedef DMat<CoefficientRingCCC> DMatCCC;

#include "dmat-LU.hpp"
#include "lapack.hpp"

namespace MatrixOppies
{
  /// @brief the rank of a matrix
  ///
  /// throws an engine_error for ring/matrix types where the function is not implemented.
  /// This version is deterministic.
  template<typename Mat>
  size_t rank(const Mat& A)
  {
    throw exc::engine_error("'rank' not implemented for this kind of matrix over this ring");
    return 0;
  }

  /// @brief the determinant of a square matrix
  ///
  /// result_det should be a previously initialized ElementType.
  /// throws an engine_error for ring/matrix types where the function is not implemented.
  template<typename Mat>
  void determinant(const Mat& A, 
                   typename Mat::ElementType& result_det)
  {
    throw exc::engine_error("'determinant' not implemented for this kind of matrix over this ring");
  }

  /// @brief the inverse of a square matrix
  ///
  /// result_inv is set to the inverse of the square matrix A, if A is invertible.
  /// result_inv should be a Mat, with the same ring/type as the input matrix A.
  ///   result_inv does not need to be the same size as A, it will be resized if needed.
  /// returns true exactly when the matrix is invertible, and result_inv has been set.
  ///
  /// throws an engine_error for ring/matrix types where the function is not implemented.
  /// throws an error if the matrix is not square.
  ///
  /// Note: the inverse of a 0 x 0 matrix is another 0 x 0 matrix.
  template<typename Mat>
  bool inverse(const Mat& A, 
               Mat& result_inv)
  {
    throw exc::engine_error("'invert' not implemented for this kind of matrix over this ring");
  }

  /// @brief the product of two matrices
  ///
  /// result_product is set to the product A*B
  /// result_product should be a Mat, with the same ring/type as the input matrices A,B.
  ///   result_product does not need to be the same size as A*B, it will be resized if needed.
  ///
  /// throws an engine_error for ring/matrix types where the function is not implemented.
  /// throws an error if the number of columns of A is not the number of rows of B.
  /// result_prod should not be the same as A or B (assertion error).
  template<typename Mat>
  void mult(const Mat& A, 
            const Mat& B, 
            Mat& result_product)
  {
    throw exc::engine_error("'mult matrices' not implemented for this kind of matrix over this ring");
  }

  /// @brief the left or right null space of a matrix
  ///
  /// if right_side is true then 
  ///   result_nullspace is set to the matrix whose columns form a basis for {x | Ax = 0}.
  /// if right_side is false then
  ///   result_nullspace is set to the matrix whose rows form a basis for {x | xA = 0}.
  /// Returns the dimension of the nullspace.
  ///
  /// result_nullspace should be a Mat, with the same ring/type as the input matrix A.
  ///   result_nullspace does not need to be the correct size, it will be resized if needed.
  ///
  /// throws an engine_error for ring/matrix types where the function is not implemented.
  template<typename Mat>
  size_t nullSpace(const Mat& A, 
                   bool right_side, 
                   Mat& result_nullspace) 
  {
    throw exc::engine_error("'nullSpace' not implemented for this kind of matrix over this ring");
  }

  /// @brief solve a linear equation AX=B or XA=B
  ///
  /// if right_side is true then 
  ///   X is set to a matrix which solves AX=B.
  /// if right_side is false then
  ///   X is set to a matrix which solves XA=B.
  ///
  /// true is returned iff this equation has a solution.
  ///
  /// declare_A_is_invertible is a hint: if true, then A is assumed to be a square invertible matrix.
  ///   If A is not invertible, and declare_A_is_invertible is true, then the routine may either fail or crash.
  /// if declare_A_is_invertible is false, then no such assumption is made.
  template<typename Mat>
  bool solveLinear(const Mat& A, 
                   const Mat& B, 
                   bool right_side, 
                   Mat& X, 
                   bool declare_A_is_invertible)
  {
    throw exc::engine_error("'solveLinear' not implemented for this kind of matrix over this ring");
    return false;
  }

  /// @brief solve AX=B, return true if the system has a solution.
  template<typename Mat>
  bool solveLinear(const Mat& A, 
                   const Mat& B, 
                   Mat& X)
  {
    return solveLinear(A,B,true,X,false);
  }

  /// @brief Returns either the row or column rank profile of A
  ///
  /// if row_profile is true, then row profile is computed, otherwise
  /// the column profile is computed.
  ///
  /// The return value is an ascending sequence of non-negative integers
  /// with an entry a occuring iff the submatrix of A of the first
  /// (a-1) rows (resp columns) has lower rank than the submatrix of the 
  /// first a rows (resp columns).  
  ///
  /// Notice that if the matrix is non-zero and the first row is 
  /// non-zero, then the first entry will be 0.
  template<typename Mat>
  M2_arrayintOrNull rankProfile(const Mat& A, 
                                bool row_profile)
  {
    throw exc::engine_error("'rankProfile' not implemented for this kind of matrix over this ring");
  }

  /// @brief Set C += A*B
  /// 
  /// Throws an exception if not yet implementd for this ring/matrix type.
  /// The sizes of C,A,B must be compatible.  These are checked only via assertions.
  template<typename Mat>
  void addMultipleTo(Mat& C, 
                     const Mat& A, 
                     const Mat& B)
  // C = C + A*B
  {
    throw exc::engine_error("'addMultipleTo' not implemented for this kind of matrix over this ring");
  }

  /// @brief Set C -= A*B
  /// 
  /// Throws an exception if not yet implementd for this ring/matrix type.
  /// The sizes of C,A,B must be compatible.  These are checked only via assertions.
  template<typename Mat>
  void subtractMultipleTo(Mat& C, 
                          const Mat& A, 
                          const Mat& B)
  // C = C - A*B
  {
    throw exc::engine_error("'subtractMultipleTo' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat>
  bool solve(const Mat& A, 
             const Mat& B, 
             Mat& X)
  {
    throw exc::engine_error("'solve' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat>
  bool nullspaceU(const Mat& A, 
                  Mat& X)
  {
    throw exc::engine_error("'nullspaceU' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat>
  M2_arrayintOrNull LU(const Mat& A, 
                       Mat& L,
                       Mat& U)
  {
    throw exc::engine_error("'LU' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat, typename Mat2>
  bool eigenvalues(const Mat& A, 
                   Mat2& eigenvals)
  {
    throw exc::engine_error("'eigenvalues' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat, typename Mat2>
  bool eigenvaluesHermitian(const Mat& A, 
                            Mat2& eigenvals)
  {
    throw exc::engine_error("'eigenvalues' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat, typename Mat2, typename Mat3>
  bool eigenvectors(const Mat& A, 
                    Mat2& eigenvals,
                    Mat3& eigenvecs)
  {
    throw exc::engine_error("'eigenvectors' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat, typename Mat2, typename Mat3>
  bool eigenvectorsHermitian(const Mat& A, 
                             Mat2& eigenvals,
                             Mat3& eigenvecs)
  {
    throw exc::engine_error("'eigenvectors' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat>
  bool leastSquares(const Mat& A, 
                    const Mat& B, 
                    Mat& X,
                    bool assume_full_rank)
  {
    throw exc::engine_error("'leastSquares' not implemented for this kind of matrix over this ring");
  }

  template<typename Mat, typename Mat2>
  bool SVD(const Mat& A, 
           Mat2& Sigma, 
           Mat& U,
           Mat& Vt,
           int strategy)
  {
    throw exc::engine_error("'SVD' not implemented for this kind of matrix over this ring");
  }

  
#ifdef HAVE_FFLAS_FFPACK
  // Functions for DMatZZpFFPACK

  size_t rank(const DMatZZpFFPACK& A);

  void determinant(const DMatZZpFFPACK& A, 
                   ZZpFFPACK::ElementType& result_det);

  bool inverse(const DMatZZpFFPACK& A, 
               DMatZZpFFPACK& result_inv);

  void mult(const DMatZZpFFPACK& A, 
            const DMatZZpFFPACK& B, 
            DMatZZpFFPACK& result_product);

  size_t nullSpace(const DMatZZpFFPACK& A, 
                   bool right_side, 
                   DMatZZpFFPACK& result_nullspace);

  bool solveLinear(const DMatZZpFFPACK& A, 
                   const DMatZZpFFPACK& B, 
                   DMatZZpFFPACK& X);

  bool solveLinear(const DMatZZpFFPACK& A, 
                   const DMatZZpFFPACK& B, 
                   bool right_side, 
                   DMatZZpFFPACK& X, 
                   bool declare_A_is_invertible);

  M2_arrayintOrNull rankProfile(const DMatZZpFFPACK& A, 
                                bool row_profile);

  void addMultipleTo(DMatZZpFFPACK& C, 
                     const DMatZZpFFPACK& A, 
                     const DMatZZpFFPACK& B);

  void subtractMultipleTo(DMatZZpFFPACK& C, 
                          const DMatZZpFFPACK& A, 
                          const DMatZZpFFPACK& B);
#endif

#ifdef HAVE_FLINT
  // Functions for DMatZZ

  inline size_t rank(const DMatZZ& A) { 
    std::cout << "calling flint rankZZ code" << std::endl;
    return fmpz_mat_rank(A.fmpz_mat()); 
  }

  inline void determinant(const DMatZZ& A, 
                          M2::ARingZZ::ElementType& result_det) 
  {
    fmpz_mat_det(& result_det, A.fmpz_mat());
  }

  inline bool inverse(const DMatZZ& A, 
                      DMatZZ& result_inv) 
  {
    DMatZZ::ElementType den;
    A.ring().init(den);
    bool result = fmpz_mat_inv(result_inv.fmpz_mat(), &den, A.fmpz_mat());
    if (!fmpz_is_pm1(&den)) 
      result = false;
    A.ring().clear(den);
    return result;
  }

  inline void mult(const DMatZZ& A, 
                   const DMatZZ& B, 
                   DMatZZ& result_product) 
  {
    // The A1 and B1 on the next line are switched because the memory layout expected
    // is the transpose of what we have for DMat.
    fmpz_mat_mul(result_product.fmpz_mat(), A.fmpz_mat(), B.fmpz_mat());
  }

  inline size_t nullSpace(const DMatZZ& A, 
                          DMatZZ& result_nullspace) 
  {
    long rank = fmpz_mat_nullspace(result_nullspace.fmpz_mat(), A.fmpz_mat());
    return (A.numColumns() - rank);
  }

  inline size_t nullSpace(const DMatZZ& A, 
                          bool right_side, 
                          DMatZZ& result_nullspace) 
  {
    if (not right_side)
      throw exc::engine_error("'nullSpace' not implemented for this kind of matrix over this ring");
    return nullSpace(A, result_nullspace);
  }

  inline bool solveLinear(const DMatZZ& A, 
                          const DMatZZ& B, 
                          DMatZZ& X) 
  {
    DMatZZ::ElementType den;
    A.ring().init(den);
    bool result = fmpz_mat_solve(X.fmpz_mat(), &den, B.fmpz_mat(), A.fmpz_mat());
    if (!fmpz_is_pm1(&den)) 
      result = false;
    A.ring().clear(den);
    return result;
  }
  
  inline bool solveLinear(const DMatZZ& A, 
                          const DMatZZ& B, 
                          bool right_side, 
                          DMatZZ& X, 
                          bool declare_A_is_invertible)
  {
    //TODO: write this routine in the cases which are not handled
    if (not right_side or not declare_A_is_invertible)
      throw exc::engine_error("'solveLinear' not implemented for this kind of matrix over this ring");
    return solveLinear(A,B,X);
  }

  inline M2_arrayintOrNull rankProfile(const DMatZZ& A, 
                                       bool row_profile)
  {
    throw exc::engine_error("'rankProfile' not implemented for this kind of matrix over this ring");
  }

  inline void addMultipleTo(DMatZZ& C, 
                            const DMatZZ& A, 
                            const DMatZZ& B)
  {
    DMatZZ D(C.ring(), A.numRows(), B.numColumns());
    fmpz_mat_mul(D.fmpz_mat(), A.fmpz_mat(), B.fmpz_mat());
    fmpz_mat_add(C.fmpz_mat(), C.fmpz_mat(), D.fmpz_mat());
  }

  inline void subtractMultipleTo(DMatZZ& C, 
                                 const DMatZZ& A, 
                                 const DMatZZ& B)
  {
    DMatZZ D(C.ring(), A.numRows(), B.numColumns());
    fmpz_mat_mul(D.fmpz_mat(), A.fmpz_mat(), B.fmpz_mat());
    fmpz_mat_sub(C.fmpz_mat(), C.fmpz_mat(), D.fmpz_mat());
  }
#endif

#ifdef HAVE_FLINT
// Functions for DMatZZpFlint

  inline size_t rank(const DMatZZpFlint& A) 
  { 
    std::cout << "calling flint rank code" << std::endl;
    return nmod_mat_rank(A.nmod_mat()); 
  }

  inline void determinant(const DMatZZpFlint& A, 
                          DMatZZpFlint::ElementType& result_det) 
  {
    result_det = nmod_mat_det(A.nmod_mat());
  }

  inline bool inverse(const DMatZZpFlint& A, 
                      DMatZZpFlint& result_inv) 
  {
    DMatZZpFlint& B = const_cast<DMatZZpFlint&>(A);
    return nmod_mat_inv(result_inv.nmod_mat(), B.nmod_mat());
  }
  
  inline void mult(const DMatZZpFlint& A, 
                   const DMatZZpFlint& B, 
                   DMatZZpFlint& result_product) 
  {
    DMatZZpFlint& A1 = const_cast<DMatZZpFlint&>(A); // needed because nmod_mat_mul doesn't declare params const
    DMatZZpFlint& B1 = const_cast<DMatZZpFlint&>(B);
    // The A1 and B1 on the next line are switched because the memory layout expected
    // is the transpose of what we have for DMat.
    nmod_mat_mul(result_product.nmod_mat(), B1.nmod_mat(), A1.nmod_mat());
  }
  
  inline size_t nullSpace(const DMatZZpFlint& A, 
                          DMatZZpFlint& result_nullspace) 
  {
    DMatZZpFlint& A1 = const_cast<DMatZZpFlint&>(A); // needed because nmod_mat_solve doesn't declare params const
    long rank = nmod_mat_nullspace(result_nullspace.nmod_mat(), A1.nmod_mat());
    return (A.numColumns() - rank);
  }
  
  inline size_t nullSpace(const DMatZZpFlint& A, 
                          bool right_side, 
                          DMatZZpFlint& result_nullspace)
  {
    //TODO: WRITE ME
    if (not right_side)
      throw exc::engine_error("'nullSpace' for left-side not implemented for this kind of matrix over this ring");
    return nullSpace(A,true,result_nullspace);
  }
  
  inline bool solveLinear(const DMatZZpFlint& A, 
                          const DMatZZpFlint& B, 
                          DMatZZpFlint& X) 
  {
    DMatZZpFlint& A1 = const_cast<DMatZZpFlint&>(A); // needed because nmod_mat_solve doesn't declare params const
    DMatZZpFlint& B1 = const_cast<DMatZZpFlint&>(B);
    return nmod_mat_solve(X.nmod_mat(), B1.nmod_mat(), A1.nmod_mat());
  }

  inline bool solveLinear(const DMatZZpFlint& A, 
                          const DMatZZpFlint& B, 
                          bool right_side, 
                          DMatZZpFlint& X, 
                          bool declare_A_is_invertible)
  {
    //TODO: WRITE ME
    if (not right_side or not declare_A_is_invertible)
      throw exc::engine_error("'solveLinear' not implemented for this kind of matrix over this ring");
    return solveLinear(A,B,X);
  }

  inline M2_arrayintOrNull rankProfile(const DMatZZpFlint& A, 
                                       bool row_profile)
  {
    //TODO: WRITE ME
    throw exc::engine_error("'rankProfile' not implemented for this kind of matrix over this ring");
  }

  inline void addMultipleTo(DMatZZpFlint& C, 
                            const DMatZZpFlint& A, 
                            const DMatZZpFlint& B)
  {
    DMatZZpFlint D(C.ring(), A.numRows(), B.numColumns());
    nmod_mat_mul(D.nmod_mat(), A.nmod_mat(), B.nmod_mat());
    nmod_mat_add(C.nmod_mat(), C.nmod_mat(), D.nmod_mat());
  }

  inline void subtractMultipleTo(DMatZZpFlint& C, 
                                 const DMatZZpFlint& A, 
                                 const DMatZZpFlint& B)
  {
    DMatZZpFlint D(C.ring(), A.numRows(), B.numColumns());
    nmod_mat_mul(D.nmod_mat(), A.nmod_mat(), B.nmod_mat());
    nmod_mat_sub(C.nmod_mat(), C.nmod_mat(), D.nmod_mat());
  }
#endif

#ifdef HAVE_FLINT
  // Functions for DMatQQFlint

  inline size_t rank(const DMatQQFlint& A) { 
    std::cerr << "calling flint rank code" << std::endl;
    // fmpq_mat has no rank function.
    // So we clear denominators row-wise (or column-wise), and compute the rank of that matrix.
    fmpz_mat_t m1;
    fmpz_mat_init(m1, A.numRows(), A.numColumns());
    fmpq_mat_get_fmpz_mat_rowwise(m1, NULL, A.fmpq_mat());
    fmpz_mat_print_pretty(m1);
    std::cerr << "calling fmpz_mat_rank" << std::endl;
    size_t rk = fmpz_mat_rank(m1);
    std::cerr << "about to clear m1" << std::endl;
    fmpz_mat_clear(m1);
    std::cerr << "returning " << rk << std::endl;
    return rk;
  }

  inline void determinant(const DMatQQFlint& A, 
                          M2::ARingQQFlint::ElementType& result_det) 
  {
    fmpq_mat_det(&result_det, A.fmpq_mat());
  }

  inline bool inverse(const DMatQQFlint& A, 
                      DMatQQFlint& result_inv) 
  {
    return fmpq_mat_inv(result_inv.fmpq_mat(), A.fmpq_mat());
  }

  inline void mult(const DMatQQFlint& A, 
                   const DMatQQFlint& B, 
                   DMatQQFlint& result_product) 
  {
    std::cout << "calling flintQQ matrix mult code" << std::endl;
    // The A and B on the next line are switched because the memory layout expected
    // is the transpose of what we have for DMat.
    fmpq_mat_mul(result_product.fmpq_mat(), A.fmpq_mat(), B.fmpq_mat());
  }

  inline size_t nullSpace(const DMatQQFlint& A, 
                          DMatQQFlint& result_nullspace) 
  {
    //TODO: WRITE ME
    //DMatQQFlint& A1 = const_cast<DMatQQFlint&>(A); // needed because fmpq_mat_solve doesn't declare params const
    //    long rank = fmpq_mat_nullspace(result_nullspace.fmpq_mat(), A1.fmpq_mat());
    //    return (A.numColumns() - rank);
    return 0;
  }
  inline size_t nullSpace(const DMatQQFlint& A, 
                          bool right_side, 
                          DMatQQFlint& result_nullspace) 
  {
    //TODO: write this routine in the cases which are not handled
    if (not right_side)
      throw exc::engine_error("'nullSpace' for left-side not implemented for this kind of matrix over this ring");
    return nullSpace(A,true,result_nullspace);
  }

  inline bool solveLinear(const DMatQQFlint& A, 
                          const DMatQQFlint& B, 
                          DMatQQFlint& X) 
  {
    //TODO: WRITE ME
    //DMatQQFlint& A1 = const_cast<DMatQQFlint&>(A); // needed because fmpq_mat_solve doesn't declare params const
    //DMatQQFlint& B1 = const_cast<DMatQQFlint&>(B);
    //    return fmpq_mat_solve(X.fmpq_mat(), B1.fmpq_mat(), A1.fmpq_mat());
    return false;
  }
  inline bool solveLinear(const DMatQQFlint& A, 
                          const DMatQQFlint& B, 
                          bool right_side, 
                          DMatQQFlint& X, 
                          bool declare_A_is_invertible)
  {
    //TODO: write this routine in the cases which are not handled
    if (not right_side or not declare_A_is_invertible)
      throw exc::engine_error("'solveLinear' not implemented for this kind of matrix over this ring");
    return solveLinear(A,B,X);
  }

  inline M2_arrayintOrNull rankProfile(const DMatQQFlint& A, 
                                       bool row_profile)
  {
    //TODO: WRITE ME
    throw exc::engine_error("'rankProfile' not implemented for this kind of matrix over this ring");
  }

  inline void addMultipleTo(DMatQQFlint& C, 
                            const DMatQQFlint& A, 
                            const DMatQQFlint& B)
  {
    DMatQQFlint D(C.ring(), A.numRows(), B.numColumns());
    fmpq_mat_mul(D.fmpq_mat(), A.fmpq_mat(), B.fmpq_mat());
    fmpq_mat_add(C.fmpq_mat(), C.fmpq_mat(), D.fmpq_mat());
  }

  inline void subtractMultipleTo(DMatQQFlint& C, 
                                 const DMatQQFlint& A, 
                                 const DMatQQFlint& B)
  {
    DMatQQFlint D(C.ring(), A.numRows(), B.numColumns());
    fmpq_mat_mul(D.fmpq_mat(), A.fmpq_mat(), B.fmpq_mat());
    fmpq_mat_sub(C.fmpq_mat(), C.fmpq_mat(), D.fmpq_mat());
  }
#endif

  /////////
  // RRR //
  /////////

  inline bool solve(const DMatRRR& A, 
                    const DMatRRR& B, 
                    DMatRRR& X)
  {
    return Lapack::solve(&A, &B, &X);
  }

  inline bool nullspaceU(const DMatRRR& A, 
                         DMatRRR& X)
  {
    DMatLU<Ring_RRR>::nullspaceU(&A, &X);
    return true;
  }

  inline M2_arrayintOrNull LU(const DMatRRR& A, 
                              DMatRRR& L,
                              DMatRRR& U)
  {
    return Lapack::LU(&A, &L, &U);
  }

  inline bool eigenvaluesHermitian(const DMatRRR& A, 
                            DMatRRR& eigenvals)
  {
    return Lapack::eigenvalues_symmetric(&A, &eigenvals);
  }

  inline bool eigenvalues(const DMatRRR& A, 
                          DMatCCC& eigenvals)
  {
    return Lapack::eigenvalues(&A, &eigenvals);
  }

  inline bool eigenvectorsHermitian(const DMatRRR& A, 
                                    DMatRRR& eigenvals,
                                    DMatRRR& eigenvecs)
  {
    return Lapack::eigenvectors_symmetric(&A, &eigenvals, &eigenvecs);
  }

  inline bool eigenvectors(const DMatRRR& A, 
                           DMatCCC& eigenvals,
                           DMatCCC& eigenvecs)
  {
    return Lapack::eigenvectors(&A, &eigenvals, &eigenvecs);
  }

  inline bool leastSquares(const DMatRRR& A, 
                           const DMatRRR& B, 
                           DMatRRR& X,
                           bool assume_full_rank)
  {
    if (assume_full_rank)
      return Lapack::least_squares(&A,&B,&X);
    else
      return Lapack::least_squares_deficient(&A,&B,&X);
  }

  inline bool SVD(const DMatRRR& A, 
           DMatRRR& Sigma, 
           DMatRRR& U,
           DMatRRR& Vt,
           int strategy)
  {
    if (strategy == 1)
      return Lapack::SVD_divide_conquer(&A, &Sigma, &U, &Vt);
    return Lapack::SVD(&A, &Sigma, &U, &Vt);
  }

  /////////
  // CCC //
  /////////

  inline bool solve(const DMatCCC& A, 
                    const DMatCCC& B, 
                    DMatCCC& X)
  {
    return Lapack::solve(&A, &B, &X);
  }

  inline bool nullspaceU(const DMatCCC& A, 
                  DMatCCC& X)
  {
    DMatLU<DMatCCC::CoeffRing>::nullspaceU(&A, &X);
    return true;
  }

  inline M2_arrayintOrNull LU(const DMatCCC& A, 
                              DMatCCC& L,
                              DMatCCC& U)
  {
    return Lapack::LU(&A, &L, &U);
  }

  inline bool eigenvaluesHermitian(const DMatCCC& A, 
                            DMatRRR& eigenvals)
  {
    return Lapack::eigenvalues_hermitian(&A, &eigenvals);
  }

  inline bool eigenvalues(const DMatCCC& A, 
                          DMatCCC& eigenvals)
  {
    return Lapack::eigenvalues(&A, &eigenvals);
  }

  inline bool eigenvectorsHermitian(const DMatCCC& A, 
                                    DMatRRR& eigenvals,
                                    DMatCCC& eigenvecs)
  {
    return Lapack::eigenvectors_hermitian(&A, &eigenvals, &eigenvecs);
  }

  inline bool eigenvectors(const DMatCCC& A, 
                           DMatCCC& eigenvals,
                           DMatCCC& eigenvecs)
  {
    return Lapack::eigenvectors(&A, &eigenvals, &eigenvecs);
  }

  inline bool leastSquares(const DMatCCC& A, 
                           const DMatCCC& B, 
                           DMatCCC& X,
                           bool assume_full_rank)
  {
    if (assume_full_rank)
      return Lapack::least_squares(&A,&B,&X);
    else
      return Lapack::least_squares_deficient(&A,&B,&X);
  }

  inline bool SVD(const DMatCCC& A, 
           DMatRRR& Sigma, 
           DMatCCC& U,
           DMatCCC& Vt,
           int strategy)
  {
    if (strategy == 1)
      return Lapack::SVD_divide_conquer(&A, &Sigma, &U, &Vt);
    return Lapack::SVD(&A, &Sigma, &U, &Vt);
  }

};
#endif

// Local Variables:
// compile-command: "make -C $M2BUILDDIR/Macaulay2/e "
// indent-tabs-mode: nil
// End: