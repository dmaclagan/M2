doc ///
Node
  Key
    Colon
  Headline
    ideal and submodule quotient, saturation, and annihilator routines
  Description
    Text
      This package provides various basic commutative algebra routines for working with ideals and modules.
    Tree
      :Main functionalities
	"ideal quotients and saturation"
	"module quotients, saturation, and annihilator"
  Subnodes
    (quotient, Ideal, Ideal)
    annihilator
    saturate

Node
  Key
    "ideal quotients and saturation"
  Description
    Text
      @SUBSECTION "Colon and Ideal Quotients"@

      The @TO2 {(quotient, Ideal, Ideal), "quotient"}@ of two ideals $I, J\subset R$ is ideal $I:J$ of
      elements $f\in R$ such that $f J \subset I$.
    Example
      R = QQ[a..d];
      I = ideal(a^2*b-c^2, a*b^2-d^3, c^5-d);
      J = ideal(a^2,b^2,c^2,d^2);
      I:J
      P = quotient(I,J)
    Text
      The functions @TO ":"@ and @TO "quotient"@ perform the same basic operation, however @TT "quotient"@
      takes options.

      @SUBSECTION "Saturation of Ideals"@

      The @TO2 {(saturate, Ideal, Ideal), "saturation"}@ of an ideal $I\subset R$ with respect to another
      ideal $J\subset R$ is the ideal $I:J^\infty$ of elements $f\in R$ such that $f J^N\subset I$ for some
      $N$ large enough. If the ideal $J$ is not given, the ideal generated by the variables of the ring $R$ is used.

      For example, one way to homogenize an ideal is to homogenize the generators and then saturate with respect
      to the homogenizing variable.
    Example
      R = ZZ/32003[a..d];
      I = ideal(a^3-b, a^4-c)
      Ih = homogenize(I, d)
      saturate(Ih, d)

-- TODO
Node
  Key
    "module quotients, saturation, and annihilator"
  Description
    Text
      @SUBSECTION "Colon and Module Quotients"@

      There are two notions associated to the colon construction for modules.

      Similar to the case of ideals, the @TO2 {(quotient, Module, Module), "quotient"}@ of two $R$-modules
      $M, N$ contained in the same @TO ambient@ module is an ideal $M:N$ of elements $f\in R$ such that
      $f N \subset M$. This is equivalent to the @TO annihilator@ of the quotient module $(M+N)/M$.
-- TODO:
--    Example
    Text
-- TODO: what is the ambient module assumed to be?
      The @TO2 {(quotient, Module, Ideal), "quotient"}@ of an $R$-module $M\subset F$ with respect to
      an ideal $J\subset R$ is the module $M:_F J$ of elements $f\in F$ such that $J f\subset M$.
-- TODO:
--    Example
    Text
      @SUBSECTION "Saturation of Modules"@

      The @TO2 {(saturate, Module, Ideal), "saturation"}@ of an $R$-module $M\subset F$ with respect to
      an ideal $J\subset R$ is an $R$-module $M:_F J^\infty$ of elements $f\in F$ such that $J^N f\subset M$
      for some $N$ large enough. If the ideal $J$ is not given, the ideal generated by the variables of the ring $R$ is used.

      If $M=M:_F J^\infty$ (or, equivalently, $M=M:_F J$), we say that $M$ is saturated with respect to $J$.
      We can use this command to remove graded submodules of finite length.
    Example
      R = ZZ/32003[a..d];
      m = ideal vars R
      M = R^1 / (a * m^2)
      M / saturate 0_M
    Text
      @SUBSECTION "Module Annihilators"@

      The @TO annihilator@ of an $R$-module $M$ is the ideal $\mathrm{ann}(M) = \{ f \in R | f M = 0 \}$.
    Example
      R = QQ[a..i];
      M = cokernel genericMatrix(R,a,3,3)
      annihilator M
    Text
      You may also use the abbreviation @TT "ann"@:
    Example
      ann (M/(a*M))
///

for n in {BasisElementLimit, PairLimit, DegreeLimit} do
document {
    Key => {[quotient, n], [saturate, n]},
    PARA {"The value for this optional argument for ", TO saturate, " and ", TO quotient, " is passed through to ", TO gb, "." }}
