  %t0 = fcmp oeq float 2.000000, 2.000000
  %a = alloca float
  %t1 = fadd float 2.000000, 2.000000
store float %t1, float* a
  %b = alloca float
  %t2 = fadd float 1.000000, 1.000000
store float %t2, float* b
  br i1 %t0, label %label_then_3, label %label_else_3
label_then_3:
  br label %label_end_3
label_else_3:
  br label %label_end_3
label_end_3:
